#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
	double y ,xp, xk, x, dx, eps, a=0, R = 0, S = 0;
	int n = 0;
	
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "ln(1-x)" << " |"
		<< setw(7) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		y = log1p(-x);
		n = 1; // вираз залежить від умови завдання варіанту
		a = x;
		S = a;
		do {
			n++;
			R = (x*n-x)/n; // вираз залежить від умови завдання варіанту
			a *= R;
			S += a;
		}
		while (abs(a)>=eps);
		S *= -1;
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << y << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}
