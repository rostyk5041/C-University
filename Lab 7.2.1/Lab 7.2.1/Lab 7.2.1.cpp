#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main();
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int k, const int n);
int MinMax(int** a, const int k, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -50;
	int High = 50;
	int rowCount, colCount;
	cout << "k= "; cin >> rowCount;
	cout << "n= "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	MinMax(a, rowCount, colCount);
	int minMax = MinMax(a, rowCount, colCount);
	cout << "minMax=" << minMax << endl; 
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int MinMax(int** a, const int rowCount, const int colCount)
{
	int* max = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		max[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] > max[i])
				max[i] = a[i][j];
	}
	int min = max[0];
	for (int i = 1; i < rowCount; i++)
		if (max[i] < min)
			min = max[i];
	delete[] max;
	return min;
}
