#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& max);
void MinMaxRows(int** a, const int rowCount, const int colCount, int rowNo, int& min);
void CreateRow(int** a, const int rowNo, const int colCount,const int Low,
	const int High, int colNo) 

{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& max)
{
	if (a[rowNo][colNo] > max)
		max = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MaxRow(a, rowNo, colCount, colNo + 1, max);
}
void MinMaxRows(int** a, const int rowCount, const int colCount, int rowNo, int& min)
{
	int max = a[rowNo][0];
	MaxRow(a, rowNo, colCount, 1, max);
	if (rowNo == 0)
		min = max;
	if (max < min)
		min = max;
	if (rowNo < rowCount - 1)
		MinMaxRows(a, rowCount, colCount, rowNo + 1, min);
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -50;
	int High = 50;
	int rowCount, colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	CreateRows(a, rowCount, colCount, Low, High, 0);
	PrintRows(a, rowCount, colCount, 0);
	int max,min;
	int rowNo = 0;
	int colNo = 0;
	MaxRow(a, rowNo, colCount, 0, max);
	MinMaxRows(a, rowCount, colCount, 0, min);
	cout << "MinMax=" << min << endl;
	return 0;
}