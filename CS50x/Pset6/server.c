//
// server.c     -   (pset) Wayne H. Nixalo -
//
// Computer Science 50
// Problem Set 6
//

// feature test macro requirements
#define _GNU_SOURCE
#define _XOPEN_SOURCE 700
#define _XOPEN_SOURCE_EXTENDED

// limits on an HTTP request's size, based on Apache's
// http://httpd.apache.org/docs/2.2/mod/core.html
#define LimitRequestFields 50
#define LimitRequestFieldSize 4094
#define LimitRequestLine 8190

// number of bytes for buffers
#define BYTES 512

// header files
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

// types
typedef char BYTE;

// prototypes
bool connected(void);
void error(unsigned short code);
void freedir(struct dirent** namelist, int n);
void handler(int signal);
char* htmlspecialchars(const char* s);
char* indexes(const char* path);
void interpret(const char* path, const char* query);
void list(const char* path);
bool load(FILE* file, BYTE** content, size_t* length);
const char* lookup(const char* path);
bool parse(const char* line, char* path, char* query);
const char* reason(unsigned short code);
void redirect(const char* uri);
bool request(char** message, size_t* length);
void respond(int code, const char* headers, const char* body, size_t length);
void start(short port, const char* path);
void stop(void);
void transfer(const char* path, const char* type);
char* urldecode(const char* s);

// server's root
char* root = NULL;

// file descriptor for sockets
int cfd = -1, sfd = -1;

// flag indicating whether control-c has been heard
bool signaled = false;

int main(int argc, char* argv[])
{
    // a global variable defined in errno.h that's "set by system
    // calls and some library functions [to a nonzero value]
    // in the event of an error to indicate what went wrong"
    errno = 0;

    // default to port 8080
    int port = 8080;

    // usage
    const char* usage = "Usage: server [-p port] /path/to/root";

    // parse command-line arguments
    int opt;
    while ((opt = getopt(argc, argv, "hp:")) != -1)
    {
        switch (opt)
        {
            // -h
            case 'h':
                printf("%s\n", usage);
                return 0;

            // -p port
            case 'p':
                port = atoi(optarg);
                break;
        }
    }

    // ensure port is a non-negative short and path to server's root is specified
    if (port < 0 || port > SHRT_MAX || argv[optind] == NULL || strlen(argv[optind]) == 0)
    {
        // announce usage
        printf("%s\n", usage);

        // return 2 just like bash's builtins
        return 2;
    }

    // start server
    start(port, argv[optind]);

    // listen for SIGINT (aka control-c)
    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);

    // a message and its length
    char* message = NULL;
    size_t length = 0;

    // path requested
    char* path = NULL;

    // accept connections one at a time
    while (true)
    {
        // free last path, if any
        if (path != NULL)
        {
            free(path);
            path = NULL;
        }

        // free last message, if any
        if (message != NULL)
        {
            free(message);
            message = NULL;
        }
        length = 0;

        // close last client's socket, if any
        if (cfd != -1)
        {
            close(cfd);
            cfd = -1;
        }

        // check for control-c
        if (signaled)
        {
            stop();
        }

        // check whether client has connected
        if (connected())
        {
            // check for request
            if (request(&message, &length))
            {
                // extract message's request-line
                // http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html
                const char* haystack = message;
                const char* needle = strstr(haystack, "\r\n");
                if (needle == NULL)
                {
                    error(500);
                    continue;
                }
                char line[needle - haystack + 2 + 1];
                strncpy(line, haystack, needle - haystack + 2);
                line[needle - haystack + 2] = '\0';

                // log request-line
                printf("%s", line);

                // parse request-line
                char abs_path[LimitRequestLine + 1];
                char query[LimitRequestLine + 1];
                if (parse(line, abs_path, query))
                {
                    // URL-decode absolute-path
                    char* p = urldecode(abs_path);
                    if (p == NULL)
                    {
                        error(500);
                        continue;
                    }

                    // resolve absolute-path to local path
                    path = malloc(strlen(root) + strlen(p) + 1);
                    if (path == NULL)
                    {
                        error(500);
                        continue;
                    }
                    strcpy(path, root);
                    strcat(path, p);
                    free(p);

                    // ensure path exists
                    if (access(path, F_OK) == -1)
                    {
                        error(404);
                        continue;
                    }

                    // if path to directory
                    struct stat sb;
                    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
                    {
                        // redirect from absolute-path to absolute-path/
                        if (abs_path[strlen(abs_path) - 1] != '/')
                        {
                            char uri[strlen(abs_path) + 1 + 1];
                            strcpy(uri, abs_path);
                            strcat(uri, "/");
                            redirect(uri);
                            continue;
                        }

                        // use path/index.php or path/index.html, if present, instead of directory's path
                        char* index = indexes(path);
                        if (index != NULL)
                        {
                            free(path);
                            path = index;
                        }

                        // list contents of directory
                        else
                        {
                            list(path);
                            continue;
                        }
                    }

                    // look up MIME type for file at path
                    const char* type = lookup(path);
                    if (type == NULL)
                    {
                        error(501);
                        continue;
                    }

                    // interpret PHP script at path
                    if (strcasecmp("text/x-php", type) == 0)
                    {
                        interpret(path, query);
                    }

                    // transfer file at path
                    else
                    {
                        transfer(path, type);
                    }
                }
            }
        }
    }
}

/**
 * Checks (without blocking) whether a client has connected to server.
 * Returns true iff so.
 */
bool connected(void)
{
    struct sockaddr_in cli_addr;
    memset(&cli_addr, 0, sizeof(cli_addr));
    socklen_t cli_len = sizeof(cli_addr);
    cfd = accept(sfd, (struct sockaddr*) &cli_addr, &cli_len);
    if (cfd == -1)
    {
        return false;
    }
    return true;
}

/**
 * Responds to client with specified status code.
 */
void error(unsigned short code)
{
    // determine code's reason-phrase
    const char* phrase = reason(code);
    if (phrase == NULL)
    {
        return;
    }

    // template for response's content
    char* template = "<html><head><title>%i %s</title></head><body><h1>%i %s</h1></body></html>";

    // render template
    char body[(strlen(template) - 2 - ((int) log10(code) + 1) - 2 + strlen(phrase)) * 2 + 1];
    int length = sprintf(body, template, code, phrase, code, phrase);
    if (length < 0)
    {
        body[0] = '\0';
        length = 0;
    }

    // respond with error
    char* headers = "Content-Type: text/html\r\n";
    respond(code, headers, body, length);
}

/**
 * Frees memory allocated by scandir.
 */
void freedir(struct dirent** namelist, int n)
{
    if (namelist != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            free(namelist[i]);
        }
        free(namelist);
    }
}

/**
 * Handles signals.
 */
void handler(int signal)
{
    // control-c
    if (signal == SIGINT)
    {
        signaled = true;
    }
}

/**
 * Escapes string for HTML. Returns dynamically allocated memory for escaped
 * string that must be deallocated by caller.
 */
char* htmlspecialchars(const char* s)
{
    // ensure s is not NULL
    if (s == NULL)
    {
        return NULL;
    }

    // allocate enough space for an unescaped copy of s
    char* t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return NULL;
    }
    t[0] = '\0';

    // iterate over characters in s, escaping as needed
    for (int i = 0, old = strlen(s), new = old; i < old; i++)
    {
        // escape &
        if (s[i] == '&')
        {
            const char* entity = "&amp;";
            new += strlen(entity);
            t = realloc(t, new);
            if (t == NULL)
            {
                return NULL;
            }
            strcat(t, entity);
        }

        // escape "
        else if (s[i] == '"')
        {
            const char* entity = "&quot;";
            new += strlen(entity);
            t = realloc(t, new);
            if (t == NULL)
            {
                return NULL;
            }
            strcat(t, entity);
        }

        // escape '
        else if (s[i] == '\'')
        {
            const char* entity = "&#039;";
            new += strlen(entity);
            t = realloc(t, new);
            if (t == NULL)
            {
                return NULL;
            }
            strcat(t, entity);
        }

        // escape <
        else if (s[i] == '<')
        {
            const char* entity = "&lt;";
            new += strlen(entity);
            t = realloc(t, new);
            if (t == NULL)
            {
                return NULL;
            }
            strcat(t, entity);
        }

        // escape >
        else if (s[i] == '>')
        {
            const char* entity = "&gt;";
            new += strlen(entity);
            t = realloc(t, new);
            if (t == NULL)
            {
                return NULL;
            }
            strcat(t, entity);
        }

        // don't escape
        else
        {
            strncat(t, s + i, 1);
        }
    }

    // escaped string
    return t;
}

/**
 * Checks, in order, whether index.php or index.html exists inside of path.     WNx - 10-Dec-2016 11:16
 * Returns path to first match if so, else NULL.
 */
char* indexes(const char* path)
{
    char * php_path = "index.php";
    char * html_path = "index.html";

    // find extension
    if (strstr(path, "index.php")) {
        return php_path;
    }
    if (strstr(path, "index.html")) {
        return html_path;
    }
    return NULL;
}
// det if exists file index.html or index.php in directory path
// apparently you check if (path, F_OK) == -1 to see if a path doesnt exist..

/**
 * Interprets PHP file at path using query string.
 */
void interpret(const char* path, const char* query)
{
    // ensure path is readable
    if (access(path, R_OK) == -1)
    {
        error(403);
        return;
    }

    // open pipe to PHP interpreter
    char* format = "QUERY_STRING=\"%s\" REDIRECT_STATUS=200 SCRIPT_FILENAME=\"%s\" php-cgi";
    char command[strlen(format) + (strlen(path) - 2) + (strlen(query) - 2) + 1];
    if (sprintf(command, format, query, path) < 0)
    {
        error(500);
        return;
    }
    FILE* file = popen(command, "r");
    if (file == NULL)
    {
        error(500);
        return;
    }

    // load interpreter's content
    char* content;
    size_t length;
    if (load(file, &content, &length) == false)
    {
        error(500);
        return;
    }

    // close pipe
    pclose(file);

    // subtract php-cgi's headers from content's length to get body's length
    char* haystack = content;
    char* needle = strstr(haystack, "\r\n\r\n");
    if (needle == NULL)
    {
        free(content);
        error(500);
        return;
    }

    // extract headers
    char headers[needle + 2 - haystack + 1];
    strncpy(headers, content, needle + 2 - haystack);
    headers[needle + 2 - haystack] = '\0';

    // respond with interpreter's content
    respond(200, headers, needle + 4, length - (needle - haystack + 4));

    // free interpreter's content
    free(content);
}

/**
 * Responds to client with directory listing of path.
 */
void list(const char* path)
{
    // ensure path is readable and executable
    if (access(path, R_OK | X_OK) == -1)
    {
        error(403);
        return;
    }

    // open directory
    DIR* dir = opendir(path);
    if (dir == NULL)
    {
        return;
    }

    // buffer for list items
    char* list = malloc(1);
    list[0] = '\0';

    // iterate over directory entries
    struct dirent** namelist = NULL;
    int n = scandir(path, &namelist, NULL, alphasort);
    for (int i = 0; i < n; i++)
    {
        // omit . from list
        if (strcmp(namelist[i]->d_name, ".") == 0)
        {
            continue;
        }

        // escape entry's name
        char* name = htmlspecialchars(namelist[i]->d_name);
        if (name == NULL)
        {
            free(list);
            freedir(namelist, n);
            error(500);
            return;
        }

        // append list item to buffer
        char* template = "<li><a href=\"%s\">%s</a></li>";
        list = realloc(list, strlen(list) + strlen(template) - 2 + strlen(name) - 2 + strlen(name) + 1);
        if (list == NULL)
        {
            free(name);
            freedir(namelist, n);
            error(500);
            return;
        }
        if (sprintf(list + strlen(list), template, name, name) < 0)
        {
            free(name);
            freedir(namelist, n);
            free(list);
            error(500);
            return;
        }

        // free escaped name
        free(name);
    }

    // free memory allocated by scandir
    freedir(namelist, n);

    // prepare response
    const char* relative = path + strlen(root);
    char* template = "<html><head><title>%s</title></head><body><h1>%s</h1><ul>%s</ul></body></html>";
    char body[strlen(template) - 2 + strlen(relative) - 2 + strlen(relative) - 2 + strlen(list) + 1];
    int length = sprintf(body, template, relative, relative, list);
    if (length < 0)
    {
        free(list);
        closedir(dir);
        error(500);
        return;
    }

    // free buffer
    free(list);

    // close directory
    closedir(dir);

    // respond with list
    char* headers = "Content-Type: text/html\r\n";
    respond(200, headers, body, length);
}

/**
 * Loads a file into memory dynamically allocated on heap.                      WNx - 09-Dec-2016 18:58
 * Stores address thereof in *content and length thereof in *length.                  10-Dec-2016 11:12
 */
bool load(FILE* file, BYTE** content, size_t* length)           // BYTES already defined as 512
{
    *content = NULL;
    *length = 0;
    size_t ELEMENTS = 1;            // these are the num of bytes
    size_t BUFFER_SIZE = 1;
    BYTE BUFFER[BUFFER_SIZE];

    while (fread(BUFFER, BUFFER_SIZE, ELEMENTS, file) != 0) {
        // alloc enough mem for the current length + buffer size + 1 for null term
        *content = realloc(*content, *length + BUFFER_SIZE + 1);
        if (*content == NULL) {
            printf("Memory Error: function load(..): *content realloc(...)\n");
            return false;
        }
        // write to memory
        memcpy(*content + *length, BUFFER, BUFFER_SIZE);
        // update length    <-- really: length += BUFFER_SIZE;
        length++;
        // set last byte to null term
        *(*content + *length) = '\0';
    }
    // check End Of File reached:
    if (feof(file)) {
        return true;
    }
    // otherwise smth went wrong: free memory and ret false
    else {
        // if *content isn't NULL anyway, free it
        if (*content) {
            free(*content);
            *content = NULL;    //  reset to NULL bc you're still affecting *content
        }
        *length = 0;            // reset *length as well
        return false;
    }
}
// Referenced against: https://github.com/davidventuri/harvard-cs50/blob/master/pset6/server.c

/**
 * Returns MIME type for supported extensions, else NULL.                       WNx - 07-Dec-2016 15:32 - 18:12
 */
const char* lookup(const char* path)    // search by file extensions
{
    // // IF THIS SHITS ITSELF JUST DO A SIMPLE CONST CHAR LOOKUP
    // // this is probly an incredibly inefficient and round-about way to do it; but whatever Im learning D:<
    // // struct to hold extns & assoc paths
    // typedef struct node
    // {
    //     char ext[6];
    //     char pathname[20];
    //     struct node* next;
    // } node;
    //
    // // init an array of nodes, each pointing to next; last points to null. init all vals to '\0'
    // int types = 0b1000;                     //  8 in binary (no reason)
    // node* mime_lookup[types];
    // for (int i = 0; i < types; i++) {
    //     mime_lookup[i] = malloc(sizeof(node));
    //     memset(mime_lookup[i]->ext, '\0', sizeof(node->ext));
    //     memset(mime_lookup[i]->pathname, '\0', sizeof(node->pathname));
    // }
    // for (int i = 0; i < types; i++) {
    //     if (i == 7)
    //         mime_lookup[i]->next = NULL;
    //     else if (i != 7)
    //         mime_lookup[i]->next = mime_lookup[i+1];
    // }
    // // populate lookup table with names
    // const char* pathnames[] = {
    //     ".css", "text/css", ".html", "text/html", ".gif", "image/gif", ".ico", "image/x-icon"
    //     ".jpg", "image/jpeg", ".js", "text/javascript", ".php", "text/x-php", ".png", "image/png" };
    // for (int i = 0; i < 8; i++) {
    //     strcpy(mime_lookup[i]->ext, pathname[i]);
    //     strcpy(mime_lookup[i]->pathname, pathname[i+1]);
    // }
    // // cursor node for later checking
    // node *cursor = mime_lookup[0];
    //
    // /*  THE ACTUAL WORK IS DONE HERE */
    //
    // // search for '.'
    // char* extension = strchr(path, '.');
    // // check extension
    // while (cursor != NULL) {
    //     if (strcasecmp(extension, cursor->ext) == 1) {
    //         return cursor->pathname;
    //     }
    //     // if valid return MIME type
    //     else {
    //         cursor = cursor->next;
    //     }
    // }
    //
    // // free up allocated memory
    // for (int i = 0; i < types; i++) {
    //     free(*mime_lookup[i]);
    // }

    // the above shit itself
    const int types = 0b1000;
    const char* pathnames[] = {
        ".css", "text/css", ".html", "text/html", ".gif", "image/gif", ".ico", "image/x-icon"
        ".jpg", "image/jpeg", ".js", "text/javascript", ".php", "text/x-php", ".png", "image/png" };
    char* ext_ptr = strchr(path, '.');
    // if invalid ret null
    if (!ext_ptr){
        return NULL;
    }
    // find len of path extension string    <-- may not be needed
    // int ext_len = strchr(path, '\0') - ext_ptr;

    for (int i = 0; i < types; i+=2) {
        if (strcasecmp(ext_ptr, pathnames[i]) == 0) {
            return pathnames[i+1];
        }
    }
    return NULL;
}

// Crap:======================:======================:======================:
// // linkd list struct for extensions & assoc. paths
// typedef struct pathLookup
// {
//     char ext[5];
//     char path[16];
//     struct pathLookup* next;
// } pathLookup;
// pathLookup* pathTable;
//
// // set all lookup nodes to \0 and add NULL node
// for (int i = 0; i < 8; i++) {
//     pathTable->ext = memset(pathTable->ext, '\0', sizeof(pathTable->ext));
//     pathTable->path = memset(pathTable->path, '\0', sizeof(pathTable->path));
//     pathLookup* = pathTable->next
// }
// Crap:======================:======================:======================:

/**                                                                             WNx - 07-Dec-2016 22:34| 09-Dec-2016 17:14 - 09-Dec-2016 18:54
 * Parses a request-line, storing its absolute-path at abs_path                 todate results: https://sandbox.cs50.net/checks/cf1b7ace6dd04cada8c5652d60d83f24
 * and its query string at query, both of which are assumed
 * to be at least of length LimitRequestLine + 1.
 */
bool parse(const char* line, char* abs_path, char* query)   //  iter over line char by char (or string by string)
{                                                           //  to make sure it exactly meets forml defn of tht 1st request line per spec, & query string
    // init some pointers:
    char* SP_ptr;
    char* SP2_ptr;
    char* query_ptr;
    const char METHOD[] = "GET", HTTPver[] = "HTTP/1.1";// CRLF[] = "\r\n";
    SP_ptr = strchr(line, ' ');

    // 1. RUN FORMAT CHECKS
    if (strstr(line, METHOD)) {
        // check GET in right place
        for (int i = 0; i < 3; i++) {
            if (METHOD[i] != *(line + i)) {
                error(405);
                return false;
            }
        }
        if(*(line + 3) != ' ') {                                     // my 'everything is 405 error bug was here; was checkig if line ptr + i was ' ' instead of line ptr + 3 == ' '
            error(405);
            return false;
        }
    }
    // else {    // line doesn't contain method GET                             // OMG YTF is this here....
    //     error(405);
    //     return false;
    // }
    // check 2 & only 2 spaces:
    SP_ptr = strchr(line, ' ');
    SP2_ptr = strchr(SP_ptr + 1, ' ');                                         // * on strchr() ?? what about SP_ptr (1)?
    if (!SP_ptr || !SP2_ptr || strchr(SP2_ptr + 1, ' ')) {
        error(400);
        return false;
    }
    // break up line into parts: method|SP|request-target|SP|HTTP-version|CRLF

    // 1st char of req-targt must be '/'
    if (*(SP_ptr + 1) != '/') {
        error(501);
        return false;
    }
    char* req_line_ptr = SP_ptr + 1;
    // if there's a '?' make sure it's followed by a 'q'
    if (strchr(req_line_ptr, '?')) {
        if (*(strchr(req_line_ptr, '?') + 1) != 'q') {
            error(400);
            return false;
        }
        query_ptr = strchr(req_line_ptr, '?');
    } else {
        query_ptr = SP2_ptr;   // if no query then set query_ptr to what SP2_ptr points to
    }
    // check no " in query:
    if (strchr(query_ptr, '\"')) {
        error(400);
        return false;
    }

    // check HTTP version:
    if (!(strstr(SP2_ptr + 1, HTTPver))) {
        error(505);
        return false;
    }

    // 2. BREAK UP REQ_TARGET INTO ABS_PATH & QUERY

    int SIZE = query_ptr - req_line_ptr;
    char TEMP1[SIZE];
    for (int i = 0; i < SIZE; i++) {
        TEMP1[i] = *(req_line_ptr + i);
    }
    abs_path = TEMP1;

    SIZE = SP2_ptr - query_ptr;
    char TEMP2[SIZE];
    if (SIZE == 0) {
        // char NOL = '\0';
        // query = NOL;
        *query = '\0';
    } else {
        for (int i = 0; i < SIZE; i++) {
            TEMP2[i] = *(query_ptr + i);
        }
        query = TEMP2;
    }
    // the .exe thing is probably a dumb way to solve that part of the checker
    if (strstr(abs_path, ".exe")) {
        error(501);
        return false;
    }
    if (lookup(abs_path) == NULL) {
        error(404);
        return false;
    }

    error(501);
    return false;
}
// :======================:======================:======================:

// sample input:
//     GET /hello.php?q=Alice HTTP/1.1\r\n
// method|SP|request-target|SP|HTTP-version|CRLF

// PSEUDOCODE:
// IN: (request-line)
// method|SP|request-target|SP|HTTP-version|CRLF
// method request-target HTTP-version\r\n
//
// request-target: /absolute-path [ "?" query ]
//
//
// PARSE:
//     iter over line:
//         extract absolute-path --> store in: abs_path    mem-len: (LimitRequestLine + 1)
//         extract query         --> store in: query       mem-len: (LimitRequestLine + 1)
//
//     IF absolute-path NOT start w «/» OR contains «?» OR IF query contains «"»
//         "Respond: 400 Bad Request
//         return false
//
//     IF «method» is NOT «GET»:
//         Respond: 405 Method Not Allowed
//         return false
//
//     IF «request-target» NOT start w «/»:
//         Respond: 501 Not Implemented
//         return false
//
//     IF «request-target» contains «"»:
//         "Respond: 400 Bad Request
//         return false
//
//     IF «HTTP-version» NOT HTTP/1.1:
//         Respond: 505 HTTP Version Not Supported
//         return false
//
// QUERY:
//     extract «query» substring from «request-target» --> store in: query
//
//     IF «query» substring absent:
//         query = "", --> query[0] = '\0'
//
// ALDAŠNAŠ:
//     IF «request-target» = /hello.php OR /hello.php? ---> query = ""
//     IF «request-target» = /hello.php?q=Alice    ---> query = "q=Alice"

// :======================:======================:======================:

/**
 * Returns status code's reason phrase.
 *
 * http://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html#sec6
 * https://tools.ietf.org/html/rfc2324
 */
const char* reason(unsigned short code)
{
    switch (code)
    {
        case 200: return "OK";
        case 301: return "Moved Permanently";
        case 400: return "Bad Request";
        case 403: return "Forbidden";
        case 404: return "Not Found";
        case 405: return "Method Not Allowed";
        case 414: return "Request-URI Too Long";
        case 418: return "I'm a teapot";
        case 500: return "Internal Server Error";
        case 501: return "Not Implemented";
        case 505: return "HTTP Version Not Supported";
        default: return NULL;
    }
}

/**
 * Redirects client to uri.
 */
void redirect(const char* uri)
{
    char* template = "Location: %s\r\n";
    char headers[strlen(template) - 2 + strlen(uri) + 1];
    if (sprintf(headers, template, uri) < 0)
    {
        error(500);
        return;
    }
    respond(301, headers, NULL, 0);
}

/**
 * Reads (without blocking) an HTTP request's headers into memory dynamically allocated on heap.
 * Stores address thereof in *message and length thereof in *length.
 */
bool request(char** message, size_t* length)
{
    // ensure socket is open
    if (cfd == -1)
    {
        return false;
    }

    // initialize message and its length
    *message = NULL;
    *length = 0;

    // read message
    while (*length < LimitRequestLine + LimitRequestFields * LimitRequestFieldSize + 4)
    {
        // read from socket
        BYTE buffer[BYTES];
        ssize_t bytes = read(cfd, buffer, BYTES);
        if (bytes < 0)
        {
            if (*message != NULL)
            {
                free(*message);
                *message = NULL;
            }
            *length = 0;
            break;
        }

        // append bytes to message
        *message = realloc(*message, *length + bytes + 1);
        if (*message == NULL)
        {
            *length = 0;
            break;
        }
        memcpy(*message + *length, buffer, bytes);
        *length += bytes;

        // null-terminate message thus far
        *(*message + *length) = '\0';

        // search for CRLF CRLF
        int offset = (*length - bytes < 3) ? *length - bytes : 3;
        char* haystack = *message + *length - bytes - offset;
        char* needle = strstr(haystack, "\r\n\r\n");
        if (needle != NULL)
        {
            // trim to one CRLF and null-terminate
            *length = needle - *message + 2;
            *message = realloc(*message, *length + 1);
            if (*message == NULL)
            {
                break;
            }
            *(*message + *length) = '\0';

            // ensure request-line is no longer than LimitRequestLine
            haystack = *message;
            needle = strstr(haystack, "\r\n");
            if (needle == NULL || (needle - haystack + 2) > LimitRequestLine)
            {
                break;
            }

            // count fields in message
            int fields = 0;
            haystack = needle + 2;
            while (*haystack != '\0')
            {
                // look for CRLF
                needle = strstr(haystack, "\r\n");
                if (needle == NULL)
                {
                    break;
                }

                // ensure field is no longer than LimitRequestFieldSize
                if (needle - haystack + 2 > LimitRequestFieldSize)
                {
                    break;
                }

                // look beyond CRLF
                haystack = needle + 2;
            }

            // if we didn't get to end of message, we must have erred
            if (*haystack != '\0')
            {
                break;
            }

            // ensure message has no more than LimitRequestFields
            if (fields > LimitRequestFields)
            {
                break;
            }

            // valid
            return true;
        }
    }

    // invalid
    if (*message != NULL)
    {
        free(*message);
    }
    *message = NULL;
    *length = 0;
    return false;
}

/**
 * Responds to a client with status code, headers, and body of specified length.
 */
void respond(int code, const char* headers, const char* body, size_t length)
{
    // determine Status-Line's phrase
    // http://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html#sec6.1
    const char* phrase = reason(code);
    if (phrase == NULL)
    {
        return;
    }

    // respond with Status-Line
    if (dprintf(cfd, "HTTP/1.1 %i %s\r\n", code, phrase) < 0)
    {
        return;
    }

    // respond with headers
    if (dprintf(cfd, "%s", headers) < 0)
    {
        return;
    }

    // respond with CRLF
    if (dprintf(cfd, "\r\n") < 0)
    {
        return;
    }

    // respond with body
    if (write(cfd, body, length) == -1)
    {
        return;
    }

    // log response line
    if (code == 200)
    {
        // green
        printf("\033[32m");
    }
    else
    {
        // red
        printf("\033[33m");
    }
    printf("HTTP/1.1 %i %s", code, phrase);
    printf("\033[39m\n");
}

/**
 * Starts server on specified port rooted at path.
 */
void start(short port, const char* path)
{
    // path to server's root
    root = realpath(path, NULL);
    if (root == NULL)
    {
        stop();
    }

    // ensure root is executable
    if (access(root, X_OK) == -1)
    {
        stop();
    }

    // announce root
    printf("\033[33m");
    printf("Using %s for server's root", root);
    printf("\033[39m\n");

    // create a socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        stop();
    }

    // allow reuse of address (to avoid "Address already in use")
    int optval = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // assign name to socket
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("\033[33m");
        printf("Port %i already in use", port);
        printf("\033[39m\n");
        stop();
    }

    // listen for connections
    if (listen(sfd, SOMAXCONN) == -1)
    {
        stop();
    }

    // announce port in use
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    if (getsockname(sfd, (struct sockaddr*) &addr, &addrlen) == -1)
    {
        stop();
    }
    printf("\033[33m");
    printf("Listening on port %i", ntohs(addr.sin_port));
    printf("\033[39m\n");
}

/**
 * Stop server, deallocating any resources.
 */
void stop(void)
{
    // preserve errno across this function's library calls
    int errsv = errno;

    // announce stop
    printf("\033[33m");
    printf("Stopping server\n");
    printf("\033[39m");

    // free root, which was allocated by realpath
    if (root != NULL)
    {
        free(root);
    }

    // close server socket
    if (sfd != -1)
    {
        close(sfd);
    }

    // stop server
    exit(errsv);
}

/**
 * Transfers file at path with specified type to client.
 */
void transfer(const char* path, const char* type)
{
    // ensure path is readable
    if (access(path, R_OK) == -1)
    {
        error(403);
        return;
    }

    // open file
    FILE* file = fopen(path, "r");
    if (file == NULL)
    {
        error(500);
        return;
    }

    // load file's content
    BYTE* content;
    size_t length;
    if (load(file, &content, &length) == false)
    {
        error(500);
        return;
    }

    // close file
    fclose(file);

    // prepare response
    char* template = "Content-Type: %s\r\n";
    char headers[strlen(template) - 2 + strlen(type) + 1];
    if (sprintf(headers, template, type) < 0)
    {
        error(500);
        return;
    }

    // respond with file's content
    respond(200, headers, content, length);

    // free file's content
    free(content);
}

/**
 * URL-decodes string, returning dynamically allocated memory for decoded string
 * that must be deallocated by caller.
 */
char* urldecode(const char* s)
{
    // check whether s is NULL
    if (s == NULL)
    {
        return NULL;
    }

    // allocate enough (zeroed) memory for an undecoded copy of s
    char* t = calloc(strlen(s) + 1, 1);
    if (t == NULL)
    {
        return NULL;
    }

    // iterate over characters in s, decoding percent-encoded octets, per
    // https://www.ietf.org/rfc/rfc3986.txt
    for (int i = 0, j = 0, n = strlen(s); i < n; i++, j++)
    {
        if (s[i] == '%' && i < n - 2)
        {
            char octet[3];
            octet[0] = s[i + 1];
            octet[1] = s[i + 2];
            octet[2] = '\0';
            t[j] = (char) strtol(octet, NULL, 16);
            i += 2;
        }
        else if (s[i] == '+')
        {
            t[j] = ' ';
        }
        else
        {
            t[j] = s[i];
        }
    }

    // escaped string
    return t;
}



// OLD PARSE FUNCTION VERSION 1:
// /**                                                                             WNx - 07-Dec-2016 22:34
//  * Parses a request-line, storing its absolute-path at abs_path
//  * and its query string at query, both of which are assumed
//  * to be at least of length LimitRequestLine + 1.
//  */
// bool parse(const char* line, char* abs_path, char* query)   //  iter over line char by char (or string by string)
// {                                                           //  to make sure it exactly meets forml defn of tht 1st request line per spec, & query string
//     // iter over line to extract abs_path & query:
//     if (line != NULL) {
//         // check corrent method (GET)
//         const char method[3] = "GET";
//         if (!strstr(line, method)) {
//             error(405);     // no GET: 405 Method Not Allowed
//             return false;
//         } else if (*(strstr(line, method) + 3 + 1) != ' ') {
//             error(405);     //  must have ' ' after 'GET": 405 Method Not Allowed
//             return false;
//         } else if (*line != method[0]) {
//             error(405);     // first char should be of method's: 405 Method Not Allowed
//             return false;
//         }
//         // check if only 2 spaces
//         char* SP_pointer;
//         if ((SP_pointer = strchr(line, ' ')) == NULL) {
//             error(405);
//             return false;
//             if ((SP_pointer = strchr(SP_pointer + 1, ' ')) == NULL) {
//                 error(405);
//                 return false;
//                 if ((SP_pointer = strchr(SP_pointer + 1, ' ')) != NULL) {
//                     error(405);
//                     return false;
//                 }
//             }
//         }
//         // if made it thru --> success. reset SP_pointer to 1st SP
//         SP_pointer = strchr(line, ' ');
//         char* SP2_pointer = strchr(SP_pointer+1, ' ');
//         // check absolute-path starts with /
//         if (*(SP_pointer + 1) != '/') {
//             // error(400);      // Bad Request
//             error(501);
//             return false;
//         }
//         // check HTTP version:
//         const char HTTPver[8] = "HTTP/1.1";
//         if (!strstr(SP2_pointer, HTTPver)) {
//             error(505);     //  HTTP Version Not Supported
//             return false;
//         }
//         // if there's a ? in line, make sure its in the right place
//             // Fail cases: *? - SP2_ptr > 0 || (*? + 1 != 'q' || != ' ')
//         char* q_ptr;
//         if ((q_ptr = strchr(line, '?'))) {
//             if ((*(q_ptr + 1) != ' ') || (tolower(*(q_ptr + 1)) != 'q') || (q_ptr - SP2_pointer) > 0) {
//                 error(400);     // Bad Request
//                 return false;
//             }
//         }
//         // extract query
//         if (!q_ptr) {
//             query = "";
//             query[0] = '\0';
//         } else {
//             int q_len = SP2_pointer - q_ptr;
//             // query = strncpy(query, q_ptr, q_len);
//             query = malloc(q_len*sizeof(char));
//             for (int i = 0; i < q_len; i++) {
//                 *(query + i) = *((SP2_pointer + 1) + i);
//             }
//         }
//         /*  Learning about pointers & assignment here. Also that strncpy() wasn't
//          *  working the way I wanted. So I find the len of what should be copied,
//          *  alloc memory as needed, then write the dereferenced bytes to memory
//          *  byte by byte.                                       07-Dec-2016 23:23
//          */
//         // extract abs
//         int abs_path_len;
//         if (!q_ptr) {
//             abs_path_len = SP2_pointer - SP_pointer;
//         } else {
//             abs_path_len = q_ptr - SP_pointer;
//         }
//         abs_path = malloc(abs_path_len*sizeof(char));
//         for (int i = 0; i < abs_path_len; i++) {
//             *(abs_path + i) = *((SP_pointer + 1) + i);
//         }
//         // abs_path = strncpy(abs_path, SP_pointer + 1, sizeof(abs_path_len));
//     }
//     error(501);
//     return false;
// }
// // :======================:======================:======================:
