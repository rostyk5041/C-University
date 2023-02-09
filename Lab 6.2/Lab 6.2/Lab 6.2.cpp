#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min && a[i]%2==0)
			min = a[i];
	return min;
}

int IMin(int* a, const int size, int i, int &min)
{
	int imin = -1;
	if (a[i] < min && a[i]%2==0)
		min = a[i],imin=i;
	if (i < size - 1)
		return IMin(a, size, i + 1,min);
	if (imin == -1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0; // потрібно щось повернути, але чому 0?
	}
	else
		return imin;
}
int Sort(int* a, int i, int imin) // метод обміну (бульбашки)
{
	int tmp = a[i];
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
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	Min(a, n);
	int min= Min(a, n);
	IMin(a, n,0,min);
	int imin = IMin(a, n,0,min);
	cout << "imin = " << imin << endl;
	cout << "min = " << min << endl;
	Sort(a, 0, imin);
	Print(a, n, 0);
	return 0;
}
