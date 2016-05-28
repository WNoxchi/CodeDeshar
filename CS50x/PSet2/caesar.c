// CS50x - Intro to Computer Science
// Wayne H. Noxchi - 28-May-2016 02:42 - 28-May-2016 04:08
// Problem Set 2 - caeser.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        // fprintf(stderr, "Error: Shift key required\n");
        printf("Error: Shift key required\n");
        return 1;
    }
    int key = atoi(argv[1]);
    // printf("Enter text to be encoded:\n");
    string plaintext = GetString();
    for (int i = 0; i < strlen(plaintext); i++){
        if (isalpha(plaintext[i]) != 0){
            if (plaintext[i] >= 'a'){
                printf("%c", ((plaintext[i] - 'a' + key) % 26 + 'a'));
            } else {
                printf("%c", ((plaintext[i] - 'A' + key) % 26 + 'A'));
            }
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

/* Old Code:

string promptString();
string encodeString(string text, int key);
int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Error: Shift key required\n");
        return 1;
    }
    string plaintext, ciphertext;
    int key = atoi(argv[1]);
    plaintext = promptString();
    ciphertext = encodeString(plaintext, key);
    printf("\n%s", ciphertext);
}
string promptString(){
    printf("Enter text to be encoded:\n");
    string text = GetString();
    return text;
}
string encodeString(string text, int key){
    string ciphertext = "";
    for (int i = 0; i < strlen(text); i++){
        if (isalpha(text[i]) != 0){
            if (text[i] >= 'A' && text[i] <= 'Z')
                ciphertext += (text[i] - 'A' + key) % 26 + 'A';
            if (text[i] >= 'a' && text[i] <= 'z')
                ciphertext += (text[i] - 'a' + key) % 26 + 'a';
        }
        else {
            ciphertext += text[i];
        }
    }
    return ciphertext;
}

*/
