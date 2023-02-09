#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;
template <typename T>
void Create1(T* a, const int size, const T Low, const T High, int i)
{

	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create1(a, size, Low, High, i + 1);
}
void Create(int* a, const int size, const int Low, const int High, int i)
{

	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
template <typename T>
void Print1(T* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print1(a, size, i + 1);
	else
		cout << endl;
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
template <typename T>
T Sum1(T* a, const int size, int i)
{
	if (i < size)
		return a[i] + Sum1(a, size, i + 1);
	else
		return 0;
}
int Sum(int* a, const int size, int i)
{
	if (i < size)
		return a[i] + Sum(a, size, i + 1);
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL));
	int const n = 10;
	int a[n];
	int Low = -100;
	int High = 100;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Sum = " << Sum(a, n, 0) << endl;
	Create1(a, n, Low, High, 0);
	Print1<int>(a, n, 0);
	cout << "Sum1 = " << Sum1(a, n, 0) << endl;
	return 0;
}
