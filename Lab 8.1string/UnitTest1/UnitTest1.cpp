#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 8.1string/Lab 8.1string.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string s = "schoSQol";
			string S = "scho***ol";
			string dest = Change(s);
			Assert::AreEqual(S, dest);
		}
	};
}
