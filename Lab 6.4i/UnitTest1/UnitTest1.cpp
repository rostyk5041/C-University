#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4i/Lab 6.4i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { -5,1,10,15 };
			Assert::AreEqual(-5,Min(a,4));
		}
	};
}
