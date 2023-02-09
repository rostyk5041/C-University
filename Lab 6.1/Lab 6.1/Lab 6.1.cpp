#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
	b[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1 )
		Create(b, size, Low, High, i+1);
}
void Print(int* b, const int size, int i)
{
	cout << setw(4) << b[i];
	if (i < size - 1)
		Print(b, size, i + 1);
	else
		cout << endl;
}

int Elem(int* b, const int size,int i,int elem)
{
	if (!(b[i] % 5 == 0 && b[i] > 0))
		elem++;
	if(i<size-1)
		return Elem(b, size, i + 1, elem);
	else
		return elem;
}
int Sum(int* b, const int size, int i,int S)
{
	{
		if (!(b[i] % 5 == 0 && b[i] > 0))
			S += b[i];
		if(i<size-1)
			return Sum(b, size, i + 1, S);
		else
			return S;
	}
}
int Zamin(int * b,const int size, int i)
{
	if (!(b[i] % 5 == 0 && b[i] > 0))
		b[i] = 0;
	if (i < size-1 )
		return Zamin(b, size, i + 1);
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 22;
	int b[n];
	int Low = -40;
	int High = 50;
	Create(b, n, Low, High, 0);
	Print(b, n,0);
	cout << "elem = " << Elem(b, n, 0,0) << endl;
	cout << "S = " << Sum(b, n, 0,0) << endl;
	Zamin(b, n, 0);
	Print(b, n,0);
	return 0;
}