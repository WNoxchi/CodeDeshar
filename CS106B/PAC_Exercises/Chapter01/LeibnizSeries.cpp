/*
* File: LeibnizSeries.cpp
* ---------------------------
* PAC++ ex 1.11
* CS106B Programming Abstractions
* 26-Feb-2016 00:30
*/

#include <iostream>
using namespace std;

int main()
{
	int n = 0;;
	double approx = 1.0;

	cout << "This program will calculate the first N terms of the Leibniz approximation of pi/4." << endl;

	while (n < 1)
	{
		cout << "N: ";
		cin >> n;
	}

	if (n > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				cout << approx << " + 1/" << (1 + 2 * i);
				approx += 1.0 / (1 + 2 * i);
				cout << " = " << approx << endl;
			}
			else
			{
				cout << approx << " - 1/" << (1 + 2 * i);
				approx -= 1.0 / (1 + 2 * i);
				cout << " = " << approx << endl;
			}
		}
	}
	else
	{
		cout << "Leibniz Series approximation (pi/4): 1" << endl;
	}

	cout << "Leibniz Series approximation (pi/4): " << approx << endl;
	cout << "Pi approximation: " << (approx * 4) << endl;
}

/* Here's a more accurate way to calculate it from: http://www2.hawaii.edu/~taha/physcompclass/p1/leibniz.html
#include <iostream>
using namespace std;
const double PI = 3.141592653589793238462;        //Correct value of pi
int main() {                                     //used for comparison
	double pi = 0.0;
	for (int N = 1; N <= 1000000; N *= 10) {     //calculate the results for N=1,10,...,1000000
		pi = 0.0;
		for (int i = 1; i <= N; ++i){
			int j = 2 * i - 1;                   //denominator term
			double o = 1.0 / j;
			o = (i % 2 == 1) ? o : -1 * o;        //Odd terms are subtracted, even terms are added
			pi += o;
		}
		pi = 4 * pi;
		double error = PI - pi;
		cout << "N = \t" << N << "\t pi is \t" << pi << "\t the error is " << error << " the percent error is " << (error / PI) << endl << endl;
	}
	return 0;
}
*/
