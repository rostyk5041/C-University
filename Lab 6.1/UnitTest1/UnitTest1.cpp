#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.1/Lab 6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[] = { 5,1,11,16 };
			Zamin(b, 4, 0);
			Assert::AreEqual(0,(b[2]));
		}
	};
}
