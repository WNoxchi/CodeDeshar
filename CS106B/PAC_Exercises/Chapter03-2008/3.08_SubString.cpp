// CS106B Programming Abstractions
// Programming Abstractions in C++
// ---------------------------------------
// Wayne H. Noxchi - 3.08_SubString.cpp
// ---------------------------------------
// 29-May-2016 23:56 - 30-May-2016 00:26

/** Without using the string method substr, implement your own function
    SubString(s,pos,len), which returns the substring of s, beginning at
    position pos and including at most len characters. Make sure that your
    function correctly applies the following rules:
        a. If pos is negative, it is set to 0 so that it indicates the first
            character in the string.
        b. If len is greater than s.length()– pos, it is set to
            strlen(s) – pos so that it stops at last character.
        c. If pos is greater than s.length() - 1, SubString returns the
            empty string.                                                   **/

#include <iostream>
#include <string>
using namespace std;

/* function */
string SubString(string text, int pos, int len){
    string substring = "";
    if (pos < 0)
        pos = 0;
    if (pos > (text.length() - 1))
        return substring;
    if (len > (text.length() - pos))
        len = text.length() - pos;
    for (int i = 0; i < len; i++){
        substring += text[pos + i];
    }
    return substring;
}

/* test */
int main(){
    string input, output;
    int pos, len;
    cout << "say something Mac" << endl;
    getline(cin, input);
    cout << "starting position: ";
    cin >> pos;
    cout << "length of substring: ";
    cin >> len;
    cout << "Substring: \"" << input << "\" pos: " << pos << " len: " << len << endl;
    output = SubString(input, pos, len);
    cout << output << endl;
}
