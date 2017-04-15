// 11-Nov-2016 18:58|16-Nov-2016 09:37
// Wayne H Nixalo
// generates an encoding
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
    // ensure proper usage
    if (argc != 3) {
        stderr("Usage: ./encoder message photo\n");
        return 1;
    }
    // remember filenames
    char* mfile = argv[1];
    char* pfile = argv[2];

    // open message file
    FILE* inptr = fopen(mfile, "r");
    if (inptr == NULL) {
        stderr("Unable to open message file %s.\n", mfile);
        return 2;
    }

    // open photo file
    FILE* outptr = fopen(outfile, "w+");
    if (outptr == NULL) {
        stderr("Unable to open photo file %s.\n", pfile);
        return 3;
    }

    // read message file & convert to binary encoding:
    fread(
}
