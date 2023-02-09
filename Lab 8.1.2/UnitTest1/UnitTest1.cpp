#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 8.1.2/Lab 8.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[] = "schoSQol";
			char cs =  'S';
			char ks = 'Q';
			bool i = Include(s, cs, ks,0);
			Assert::AreEqual(true, i);
		}
	};
}
