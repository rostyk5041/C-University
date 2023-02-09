#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
	b[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(b, size, Low, High, i + 1);
}
void Print(int* b, const int size, int i)
{
	cout << setw(4) << b[i];
	if (i < size - 1)
		Print(b, size, i + 1);
	else
		cout << endl;
}
int Min(int* b, const int size, int i, int min)
{
	if (b[i] < min)
		min = b[i];
	if (i < size - 1)
		return Min(b, size, i + 1, min);
	else
		return min;
}
int IFirst(int* a, const int size, int& min, int i)
{
	if (a[i]>0)
	{
		min = a[i]; // перший елемент, що
		return i; // задовольняє умові
	} // вважаємо максимальним

	if (i < size - 1)
		return IFirst(a, size, min, i + 1);
	else
		return -1;
}
int ILast(int* a, const int size, int& max, int i)
{
	if (a[i] > 0)
	{
		max = a[i]; // перший елемент, що
		return i; // задовольняє умові
	} // вважаємо максимальним

	if (i > 0)
		return ILast(a, size, max, i - 1);
	else
		return -1;
}
int Sum(int* a, int ilast, int ifirst, int S)
{
	S += a[ifirst];
	if (ifirst < ilast-1)
		return Sum(a, ilast, ifirst + 1, S);
	else
		return S;
}
void Sort1(int* a, const int size, int i, int j) // метод обміну (бульбашки)
{
	if (a[i] == 0) {
		{ 
			int tmp = a[i];
			a[i] = a[j + 1];
			a[j + 1] = tmp;
		}
		if (j < size - i - 1) // j - номер поточного елемента
			Sort1(a, size, i, j + 1); // перехід до наступного елемента
	}
	if (i < size - 1)
		Sort1(a, size, i + 1,j);
	
}
int Elem(int* b, const int size, int i, int elem)
{
	if (b[i]==0)
		elem++;
	if (i < size-1 )
		return Elem(b, size, i + 1, elem);
	else
		return elem;
}
void Sort2(int* a, const int size, int j, int i) // метод обміну (бульбашки)
{
	if (a[j] > a[j + 1]) // якщо порушено порядок
	{ // - обмін елементів місцями
		int tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
	}
	if (j < size - 1) // j - номер поточного елемента
		Sort2(a, size,  j + 1, i); // перехід до наступного елемента
	if (i < size - 1) // i - лічильник ітерацій
		Sort2(a, size, i + 1, 0);
}

int main()
{
	srand((unsigned)time(NULL));
	int n ;
	cout << "n=";
	cin >> n;
	int* b = new int[n];
	int Low = -100;
	int High = 100;
	Create(b, n, Low, High, 0);
	b[10] = 0;
	Print(b, n, 0);
	cout << "min = " << Min(b, n, 1, b[0]) << endl;
	int min;
	int imin = IFirst(b, n, min,0);
	int max;
	int imax = ILast(b, n, max,n-1);
	cout << "first + elem=" << b[imin] << endl;
	cout << "last + elem=" << b[imax] << endl;
	cout << "S = " << Sum(b, imax, imin,0) << endl;
	Sort1(b, n, 0,-1);
	Print(b, n, 0);
	Elem(b, n, 0, 0);
	int elem= Elem(b, n, 0, 0);
	cout << "elem = " << elem << endl;
	Sort2(b, n, elem,0);
	Print(b, n, 0);
	return 0;
}