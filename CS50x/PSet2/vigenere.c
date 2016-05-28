// CS50x - Intro to Computer Science
// Problem Set 2 - vigenere.c
// Wayne H. Noxchi - 28-May-2016 10:01 - 28-May-2016 11:44

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char *argv[]){
    // key check
    if (argc != 2){
        printf("Error, cipher key required.\n");
        return 1;
    }

    string text, key = argv[1];
    int keyCount = 0, index, keyShift;

    // check cipher isalpha
    for (int i = 0; i < strlen(key); i++){
        if (isalpha(key[i]) == 0){
            printf("Error, cipher key must be alphabetical.\n");
            return 1;
        }
    }
    // get text
    // printf("Input text to be encrypted: \n");
    text = GetString();

    // encoding
    for (int i = 0; i < strlen(text); i++){
        if (isalpha(text[i]) != 0){
            index = keyCount % strlen(key);
            if (key[index] >= 'a'){
                keyShift = key[index] - 'a';
            } else {
                keyShift = key[index] - 'A';
            }
            if (text[i] >= 'a'){
                printf("%c", ((text[i] - 'a' + keyShift) % 26 + 'a'));
            } else {
                printf("%c", ((text[i] - 'A' + keyShift) % 26 + 'A'));
            }
            keyCount++;
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}

/* debugging / Old Code

printf("Cipher Size: %i\n", cipherSize);
for (int i = 0; i < strlen(key); i++){
    printf("%i - ", cipher[i]);
}
printf("\n");
for (int i = 0; i < strlen(key); i++){
    printf("%c - ", key[i]);
}

// // encoding
// for (int i = 0; i < strlen(text); i++){
//     if (isalpha(text[i])){
//         if (text[i] >= 'a'){
//             printf("%c", ((text[i] - 'a' + cipher[i % cipherSize]) % 26 + 'a'));
//             printf("[%i]", cipher[i % cipherSize + 1]);
//         } else {
//             printf("%c", ((text[i] - 'A' + cipher[i % cipherSize]) % 26 + 'A'));
//         }
//     } else {
//         printf("%c", text[i]);
//     }
// }

*/
