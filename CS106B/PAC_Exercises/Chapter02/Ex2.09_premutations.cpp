/*
* File: premutations.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.9
* CS106B Programming Abstractions
* 06-Mar-2016 04:05
*/

#include <iostream>
using namespace std;

int permute(int n, int k);

int main()
{
    cout << "Copyright Wayne H. Noxchi, 2016 Daymoxk. You know.." << endl;
    cout << "Permutation(n, k) where P(n, k) = n! / (n - k)!" << endl;
    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << "P(" << n << ", " << k << ") = " << permute(n, k) << endl;
}

int permute(int n, int k)
{
    int x = 1;
    for (int i = 0; i < (n - k); i++)
    {
        x *= n - i;
    }
    return x;
}
