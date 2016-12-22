int strcasecmp(*st1, *st2){
    returns 0 if strings equal
    returns <0 if st1 < st2
    returns >0 if st1 > st2}

char *strcpy(*dest, *src){
    dest: ptr to destntn array to do copy
    src: string to copy
returns ptr to string dest

char *strchr(const char *str, int c){}
    // search for 1st occrnce of u_char c in string ptd to by str.
returns ptr to 1st occ of c in str, or NULL if not found.

*memset(void *str, int c, size_t n){}
    // copy c for size of (n) place at *str
    char dest[100];
    memset(dest, '\0', sizeof(dest));
    // copy null-term-char startign at memloc dest for size of dest places.
returns ptr to mem area str

// copies up to n chars of string src to dest
char *strncpy(char *dest, const char *src, size_t n){}
    dest: ptr to dest array where content is to be copied
    src:  string to copy
    n     number of chars to copy from src
returns final copy of copied string

char *strstr(const char *haystack, const char *needle){}
    haystack: C string to be scanned
    needle:   small string to search for in haystack
returns ptr to 1st occ in haystack of any of entire seq of chars specd in needle
        --> or NULL ptrs if seq not present in haystack
