// Іватьо Р.М Ік-11
// Лабораторна робота № 3.4
// Варіант 6
#include <iostream>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double y; // вхідний параметр
	double R; // вхідний параметр
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;

	// розгалуження в повній формі
	if (((y + R) * (y + R) >= R * R - ((x + R) * (x + R)) && y <= 0 && x >= -R && x <= 0)
		|| (y * y <= (R * R - ((x - R) * (x - R))) && y >= 0))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}
