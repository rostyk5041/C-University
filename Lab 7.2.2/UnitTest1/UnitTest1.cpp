#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.2.2/Lab 7.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int a[3][2] =
			{
			 {20,27},
			 {16,37},
			 {19,26}
			};
			void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& max);
			void MinMaxRows(int** a, const int rowCount, const int colCount, int rowNo, int& min);
			int max, min;
			MaxRow((int**)a, 3, 2, 0, max);
			MinMaxRows((int**)a, 3, 2, 0, min);
			Assert::AreEqual(26, min);
		}
	};
}
