#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.2/Lab 6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 10,1,2,15,7,6 };
			Assert::AreEqual(10, (a, 6, 0,a[0]));
		}
	};
}
