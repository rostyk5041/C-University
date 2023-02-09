#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3.1/Lab 7.3.1.cpp"

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
			 {20,-27},
			 {16,37},
			 {19,26}
			};
			int SumRow(int** a, const int rowCount, const int colCount, int S);
			int S = SumRow((int**)a, 3, 2, 0);
			Assert::AreEqual(-27, S);
		}
	};
}
