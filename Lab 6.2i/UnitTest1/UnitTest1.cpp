#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.2i/Lab 6.2i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 10,1,2,15,7,6 };
			Assert::AreEqual(2, IMin(a, 6));
		}
	};
}
