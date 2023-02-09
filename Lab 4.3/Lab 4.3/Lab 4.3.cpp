//Lab 4.3
//Іватьо Р.М.
//ІК-11
//Варіант 6

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c, x, xp, xk, dx, F;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "F" << " |" << endl;
	cout << "---------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		if (c < 0 && b != 0)
			F = (a * x * x + b * b * x);
		else
			if (c > 0 && b == 0)
				F = (x + a) / (x + c);
			else
				F = (x / c);
		
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << F
			<< " |" << endl;
		x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}
