#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int IMin(int* a, const int size)
{
	int imin = -1;
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min && a[i] % 2 == 0)
		{
			min = a[i];
			imin = i;
		}
	if (imin==-1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0; // потрібно щось повернути, але чому 0?
	}
	return imin;
}
int Sort(int* a, int i,int imin) // метод обміну (бульбашки)
{	int tmp = a[i];
	a[i] = a[imin];
	a[imin] = tmp;
	return 0;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 10;
	int a[n];
	int Low = -20;
	int High = 20;
	Create(a, n, Low, High);
	Print(a, n);
	IMin(a, n);
	int imin = IMin(a, n);
	int min = a[IMin(a,n)];
	cout << "min = " << min << endl;
	Sort(a, 0,imin);
	Print(a, n);
	return 0;
}