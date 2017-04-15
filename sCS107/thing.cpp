// stringstreams
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string myst;
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin, myst);
    stringstream(myst) >> price;
    cout << "Enter quantity: ";
}
