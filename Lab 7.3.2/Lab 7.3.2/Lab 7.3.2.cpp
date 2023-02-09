#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int colCount, const int Low,
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
int Sum(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount - 1) 
	{
		if (j < colCount - 1)
		{
			if (a[i][j] < 0) 
				if (j < colCount - 1)
					return a[i][j] + Sum(a, rowCount, colCount, i, j);
				return Sum(a, rowCount, colCount, i, j + 1);
		}
		return Sum(a, rowCount, colCount, i, j+1);
	}
	else 
		return a[i][j];
}
bool IsMaxInRowN(int** a, const int rowNo, const int max, const int colCount,
	int colNo)
{
	if (a[rowNo][colNo] > max)
		return false;
	if (colNo < colCount - 1)
		return IsMaxInRowN(a, rowNo, max, colCount, colNo + 1);
	else
		return true;
}
bool IsMinInColK(int** a, const int colNo, const int min, const int rowCount,
	int rowNo)
{
	if (a[rowNo][colNo] < min)
		return false;
	if (rowNo < rowCount - 1)
		return IsMinInColK(a, colNo, min, rowCount, rowNo + 1);
	else
		return true;
}
void Part2_SaddlePointRow(int** a, const int rowCount, const int colCount,
	int& No, const int rowNo, int colNo)
{
	if (IsMaxInRowN(a, rowNo, a[rowNo][colNo], colCount, 0) &&
		IsMinInColK(a, colNo, a[rowNo][colNo], rowCount, 0))
	{
		cout << setw(4) << ++No << setw(6) << rowNo << setw(6) << colNo << endl;
	}
	if (colNo < colCount - 1)
		Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, colNo + 1);
}
void Part2_SaddlePointRows(int** a, const int rowCount, const int colCount,
	int& No, int rowNo)
{
	Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, 0);
	if (rowNo < rowCount - 1)
		Part2_SaddlePointRows(a, rowCount, colCount, No, rowNo + 1);
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -1;
	int High = 3;
	int rowCount, colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	CreateRows(a, rowCount, colCount, Low, High, 0);
	PrintRows(a, rowCount, colCount, 0);
	int S = Sum(a, rowCount, colCount, 0, 0);
	if (S==0)
		cout << "not found negative elem";
	else
		cout << "S=" << S << endl;
	cout << "Saddle points: max in row & min in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	Part2_SaddlePointRows(a, rowCount, colCount, No, 0);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}