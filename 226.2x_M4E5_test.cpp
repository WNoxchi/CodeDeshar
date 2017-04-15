// 07-Jun-2016 15:13
#include <iostream>
#include <string>
using namespace std;

bool strCheck(string str1, string str2);
int main() {

    string ans1    = "k_1*e^(-t)*(-2*cos(sqrt(11)*t)-sqrt(11)*sin(sqrt(11)*t)) + k_2*e^(-t)*(sqrt(11)*cos(sqrt(11)*t)-2*sin(sqrt(11)*t))";
    string ans1x   = "k_1*e^(-t)*(-2*cos(sqrt(11)*t)-sqrt(11)*sin(sqrt(11)*t)) + k_2*e^(-t)*(sqrt(11)*cos(sqrt(11)*t)-2*sin(sqrt(11)*t))";


    string ans2    = "k_1*e^(-t)*(3*cos(sqrt(11)*t))+k_2*e^(-t)*(3*cos(sqrt(11)*t))";
    string ans2x   = "k_1*e^(-t)*3*cos(sqrt(11)*t)+k_2*e^(-t)*3*sin(sqrt(11)*t)";

    cout << strCheck(ans1, ans1x) << endl;
    cout << strCheck(ans2, ans2x) << endl;

}

bool strCheck(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
