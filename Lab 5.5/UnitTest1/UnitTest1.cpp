#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.5/Lab 5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double r = f(1,1,1);
			Assert::AreEqual(1., r);
		}
	};
}
