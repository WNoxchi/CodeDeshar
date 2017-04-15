#include <iostream>
#include <string>
using namespace std;

int main() {
    // char ch = 'x';
    string str = "hu";
    // str += string() + ch;
    // cout << str << endl;

    int num = 9;
    char ch = char(9 + '0');
    cout << ch << endl;
    str += string() + ch;
    cout << str << endl;
}
