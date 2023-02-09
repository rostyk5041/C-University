// Lab_03_3.cpp
// Іватьо Р.М. 
// Лабораторна робота № 3.3
// Варіант 6
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;

	// розгалуження в повній формі
	if (x<=-5)
		y = -3;
	else
		if (-5 < x && x <= -R)
			y = (3*(R+x))/(5-R);
		else
			if (-R < x && x <= R)
				y = sqrt(R*R- x * x);
			else
				if (R < x && x <= 8)
					y = (R*x - R*R )/(8 - R);
				else
					y = R;
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	return 0;
}