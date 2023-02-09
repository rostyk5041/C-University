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
int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int iFirst(int* a, const int size)
{
	int first; // максимальний елемент
	int ifirst = -1; // індекс максимального елемента
	for (int i = 0; i < size; i++)
		if (a[i]>0)
		{
			first = a[i]; // перший елемент, що
			ifirst = i; // задовольняє умові –
			break; // вважаємо максимальним
		}
	return ifirst;
}
int iLast(int* a, const int size)
{
	int last; // 
	int ilast = -1; // індекс 
	for (int i = size-1; i > 0; i--)
		if (a[i] > 0)
		{
			last = a[i]; // перший елемент, що
			ilast = i; // задовольняє умові –
			break; // вважаємо максимальним
		}
	return ilast;
}
int Sum(int* a, int ilast, int ifirst)
{
	int S = 0;
	for (int i = ifirst; i < ilast; i++)
		S += a[i];
	return S;
}
void Sort1(int* a, const int size) // метод обміну (бульбашки)
{
	for (int i = 0; i < size; i++) // лічильник ітерацій
		if(a[i]==0)
		for (int j = -1; j < size - i; j++) // номер поточного елемента
			{ 
				int tmp = a[i];
				a[i] = a[j + 1];
				a[j + 1] = tmp;
			}
}
int Elem(int* a, const int size, int elem)
{
	for (int i = 0; i < size; i++)
		if (a[i]==0)
			elem++;
	return elem;
}
void Sort2(int* a, const int size,int elem) // метод обміну (бульбашки)
{
	for (int j = 0; j < size -elem; j++) // номер поточного елемента
		if (a[j] > a[j + 1] && a[j]!=0) // якщо порушено умову впорядкування
		{ // - обмін елементів місцями
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n=";
	cin >> n;
	int* a = new int[n];
	int Low = -50;
	int High = 50;
	Create(a, n, Low, High);
	a[10] = 0 ;
	Print(a, n);
	int ifirst = iFirst(a, n);
	int ilast = iLast(a, n);
	cout << "min = " << Min(a, n) << endl;
	cout << "first + elem=" << a[ifirst] << endl;
	cout << "last + elem=" << a[ilast] << endl;
	cout << "S = " << Sum(a, ilast, ifirst) << endl;
	Sort1(a, n);
	Print(a, n);
	Elem(a, n, 0);
	int elem= Elem(a, n, 0);
	Sort2(a, n, elem );
	Print(a, n);
	return 0;
}