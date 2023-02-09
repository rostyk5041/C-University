#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1/Lab 7.1.cpp"


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
            int S = 0;
            int k = 0;
			void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
            Assert::AreEqual(0, S);
        }
	};
}
