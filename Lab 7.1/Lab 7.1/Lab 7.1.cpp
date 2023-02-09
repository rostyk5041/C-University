#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** R, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** R, const int rowCount, const int colCount);
void Sort(int** R, const int rowCount, const int colCount);
void Change(int** R, const int row1, const int row2, const int colCount);
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 16;
	int High = 97;
	int rowCount = 8;
	int colCount = 6;
	int** R = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];
	Create(R, rowCount, colCount, Low, High);
	Print(R, rowCount, colCount);
	Sort(R, rowCount, colCount);
	Print(R, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(R, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(R, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;
	return 0;
}
void Create(int** R, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			R[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** R, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << R[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** R, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
	for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((R[i1][0] < R[i1 + 1][0])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] > R[i1 + 1][1])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] == R[i1 + 1][1] &&
					R[i1][2] < R[i1 + 1][2]))
				Change(R, i1, i1 + 1, colCount);
}
void Change(int** R, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = R[row1][j];
		R[row1][j] = R[row2][j];
		R[row2][j] = tmp;
	}
}
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (R[i][j] % 7 == 0 || i % 2!= 0 || j % 2 != 0)
			{
				S += R[i][j];
				k++;
				R[i][j] = 0;
			}
}