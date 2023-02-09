#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* b, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		b[i] = Low + rand() % (High - Low + 1);
}
void Print(int* b, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << b[i];
	cout << endl;
}
int Elem(int* b, const int size, int elem)
{
	for (int i = 0; i < size ; i++)
		if (!(b[i] % 5 == 0 && b[i] > 0))
			elem++;
	return elem;
}
int Sum(int* b, const int size,int S)
{	
	for (int i = 0; i < size; i++)
	{
		if (!(b[i] % 5 == 0 && b[i] > 0))
			S += b[i];
	}
	return S;
}
int Zamin(int* b, const int size)
{	for (int i = 0; i < size; i++)
		if (!(b[i] % 5 == 0 && b[i] > 0))
			b[i]=0;
return 0;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 22;
	int b[n];
	int Low = -40;
	int High = 50;
	Create(b, n, Low, High);
	Print(b, n);
	cout << "elem = " << Elem(b, n, 0) << endl;
	cout << "S = " << Sum(b, n,0) << endl;
	Zamin(b, n);
	Print(b, n);
	return 0;
}