#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.3/Lab 6.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 5,1,10,15 };
			Sum(a, 4, 1);
			Assert::AreEqual(1, a[1]);
		}
	};
}
