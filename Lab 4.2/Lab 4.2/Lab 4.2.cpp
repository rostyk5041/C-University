#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x, xp, xk, dx, A, B, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		A = 5 * exp(3 * x);
		if (x <= -1)
		B = 3 + sin(abs(x));
		else
			if (x > 3)
				B = 7 - (sqrt(2) * (x * x * x));
		else
			B = 2 * exp((x * 1 / 4) - 1);
	y = A - B;
	cout << "|" << setw(7) << setprecision(2) << x
		<< " |" << setw(10) << setprecision(3) << y
		<< " |" << endl;
	x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}