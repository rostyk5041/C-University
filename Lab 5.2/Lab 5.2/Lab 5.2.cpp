#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
	double y, xp, xk, x, dx, eps, R=0, s = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps ="; cin >> eps;
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
		S(x, eps, n, s);
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << y << " |"
			<< setw(10) << setprecision(5) << s << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}
void S(const double x, const double eps, int &n, double &s)
{
	n = 1; // вираз залежить від умови завдання варіанту
	double a = -x; // вираз залежить від умови завдання варіанту
	s = a;
	
	do {
		n++;
		A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
}
void A(const double x, const int n, double &a)
{
	double R = (x*n -x)/ n; // вираз залежить від умови завдання варіанту
	a *= R;
	}