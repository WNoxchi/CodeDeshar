/*
 *  CS50x Intro to Computer Science
 *  PSet 4 - recover.c
 *  Wayne Nixalo - 30-Sep-2016 16:47
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// #include <string.h>

int main(int argc, char* argv[])
{
    // ensure proper Usage
    if (argc != 1) {
        printf("Usage: ./recover\ntarget file is hard coded\n");
        return 1;
    }

    // open card file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL) {
        printf("Could not open card file.\n");
        return 2;
    }

    // jpg signatures:
    uint8_t jsig1[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t jsig2[4] = {0xff, 0xd8, 0xff, 0xe1};

    int openJpg = 0;    // jpg open indicator
    int counter = 0;    // jpg filename counter
    FILE* outptr;

    // create buffer structure
    typedef struct {
        uint8_t check[4];     // jpg signature
        uint8_t data[512];
    } BUFFER;
    BUFFER buffer;

    while (fread(buffer.data, 512, 1, inptr) > 0) {
        // add first 4 bytes to check
        for (int i = 0; i < 4; i++) {
            buffer.check[i] = buffer.data[i];
        }
        // check if jpg signature
        if ((memcmp(jsig1, buffer.check, 4) == 0) || (memcmp(jsig2, buffer.check, 4) == 0)) {
            // filename
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);

            if (!openJpg) {
                outptr = fopen(filename, "w");
                fwrite(buffer.data, sizeof(buffer.data), 1, outptr);
                openJpg = 1;
            }
            if (openJpg) {
                fclose(outptr);
                outptr = fopen(filename, "w");
                fwrite(buffer.data, sizeof(buffer.data), 1, outptr);
                counter++;
            }
        } else {
            if (openJpg) {
                fwrite(buffer.data, sizeof(buffer.data), 1, outptr);
            }
        }
    }

    // close final jpg file
    if(outptr) {
        fclose(outptr);
    }
    fclose(inptr);

    // end
    return 0;
}

/*pseudocode:
open card file
repeat until end of card:
read 512 bytes into a buffer
start of a new jpg?
	yes —>
	no  —>
already found a jpg?
	yes —>
	no  —>
close any remaining files
*/

/*  Obsolete:

// filename generator
int counter = 0, zeros;
char[3] filenumber;
if (counter < 100) zeros = 1;
if (counter < 10) zeros = 2;
for (int i = 0; i < filenumber.length(); i++) {
    if (i < zeros) {
        filenumber[i] = '0';
    }
    else {
        if (counter > 100) {
            counter = counter / 100;
            filename[i] = counter + '0';
        }
        if (counter > 10 && counter < 100) {
            counter = counter / 10;
            filename[i] = counter + '0';
        }
        else {
            filename[i] = counter + '0';
        }
    }
}


for (int i = 0; i < 4; i++) {
    if (buffer.data[i] == jsig1[i] || buffer.data[i] == jsig2[i]) {
        buffer.check[i] = buffer.data[i];
        if (i == 3) {
            startJpg = 1;
            openJpg = 1;
        }
    } else {
        startJpg = 0;
    }
}
begin write to new file
if file already open: close, open new
if (!openJpg && startJpg) {
    FILE* outptr = fopen("%03d.jpg", counter, "a");
}


//     if ((memcmp(jsig1, buffer.check, sizeof(buffer.check) == 0) || (memcmp(jsig2, buffer.check, sizeof(buffer.check)) == 0)) {


*/
