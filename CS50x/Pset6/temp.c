// WHNixalo - 07-Dec-2016 15:01
// #include <stdio.h>
// #include <string.h>
//
// int main(){
//     char src[40];
//     char dest[100];
//
//     memset(dest, '\0', sizeof(dest));
//     strcpy(src, "This is KAWKASIA!");
//     strcpy(dest, src);
//
//     for (int i = 0; i < 10; i++)
//         printf("%s\n", dest);
//     return 0;
// }
// WHNixalo - 07-Dec-2016 15:39
// # include <stdio.h>
// # include <string.h>
// int main(int argc, char *argv[]){
//
//     int i;
//     if(argc != 3){
//         printf("<exiting>\n");
//         return 1;
//     }
//     i = strcasecmp(argv[1], argv[2]);
//     if (i == 0)
//         printf("'%s' equals '%s'\n", argv[1], argv[2]);
//     else if (i > 0)
//         printf("'%s' is greater than '%s'\n", argv[1], argv[2]);
//     else if (i < 0)
//         printf("'%s' is less than '%s'\n", argv[1], argv[2]);
//     return 0;
// }
// WHNixalo - 07-Dec-2016 16:13         09-Dec-2016 14:18
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {
    // if (argc != 2) {
    //     printf("2 args for function. <exiting>\n");
    //     return 1;
    // }
    // typedef struct node
    // {
    //     char ext[5];
    //     char path[20];
    //     struct node* next;
    // } node;
    // node* lookup = malloc(sizeof(node));
    // strcpy(lookup->ext, ".exe\0");
    // strcpy(lookup->path, "/folder/program.exe\0");
    // lookup->next = NULL;
    //
    // printf("%s, %s\n",lookup->ext, lookup->path);
    // int a = 0b1000;
    // int b = 8;
    // printf("a: %d, b: %d\n", a, b);

    // char* paths[] = { "hey", "yo", "mama", "yoyoma", "ohmygod" };
    // int size = sizeof(paths) - 1;
    // printf("%d\n", size);
    // printf("%s\n", paths[3]);
    //
    // char emptystring[1] = "";
    // emptystring[0] = '\0';
    // printf("emptystring[%s]\n", emptystring);
    //
    // int num = 64;
    // printf("number: %lu\n", sizeof(num));

    // const char * M_ptr = "GET";
    // const char METHOD[] = "GET";
    // const char THING[] = "GET\r\n";
    //
    // // const char * M_ptr = METHOD;
    // // const char * T_ptr = THING;
    //
    // int i = strcasecmp(METHOD, THING);
    // // int i = strcasecmp(M_ptr, T_ptr);
    // printf("strcasecmp: \"%s\" : \"%s\" = %d\n", METHOD, THING, i);
    //
    // // const char * M_ptr = METHOD;
    // //
    // // // i = strcasecmp(argv[1], argv[2]);
    // // int i = strcasecmp(M_ptr, argv[1]);
    // // if (i == 0)
    // //     printf("'%s' equals '%s'\n", M_ptr, argv[1]);
    // // else if (i > 0)
    // //     printf("'%s' is greater than '%s'\n", M_ptr, argv[1]);
    // // else if (i < 0)
    // //     printf("'%s' is less than '%s'\n", M_ptr, argv[1]);
    //
    // // char * X = strchr(M_ptr, ' ');   // both ways work
    // char * X = strchr(METHOD, ' ');
    // if (X)
    //     printf("%s",X);
    // else
    //     printf("NOL\n");
    //
    // return 0;

    char * Lpt;
    char * Qpt;

    char * BIGSTRING = "This is a Large String. Query here.";
    char * req_line_ptr = strstr(BIGSTRING, "Large");;
    char * query_ptr = strchr(req_line_ptr, 'Q');

    int SIZE = query_ptr - req_line_ptr;
    char HOLDER[SIZE];
    for (int i = 0; i < SIZE; i++) {
        HOLDER[i] = *(req_line_ptr + i);
    }
    Lpt = HOLDER;

    // memset(Lpt, '\0', sizeof(HOLDER));
    // for (int i = 0; i < SIZE; i++) {
    //     Lpt = HOLDER;
    // }

    Qpt = "\0";
    HOLDER = "heyoo";
    // printf("Qpt: %s\n", Qpt);
    printf("Lptr: [%s]\n", Qpt);

    return 0;
}
