#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
using namespace std;
template <typename T>
void Create(T* a, const int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand() % (100 + 1);
}
void Create(int* a,const int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand() % (100 + 1);
}
template <typename T>
void Print(T* a,const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(2) << a[i] << " ";
}
void Print(int* a,const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(2) << a[i] << " ";
}
template <typename T>
T Sum(T* a, const int size)
{
	T S = 0;
	for (int i = 0; i < size; i++)
		S += a[i];
	return S;
}

int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		S += a[i];
	return S;
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n =10;
	int a[n];
	int Low = -50;
	int High = 50;
	Create(a, n);
	Print(a, n);
	cout << "S = " << Sum(a, n) << endl;
	Create<int>(a, n);
	Print<int>(a, n);
	cout << "S1 = " << Sum<int>(a, n) << endl;
	return 0;
}
