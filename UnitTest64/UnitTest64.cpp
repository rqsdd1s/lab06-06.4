#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4/lab6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		// масив 3.7, -1.2, 10.0, 8.5, -4.6, 2.9, 9.1 (n = 7)
		TEST_METHOD(TestMethod1)
		{
			double a[] = { 3.7, -1.2, 10.0, 8.5, -4.6, 2.9, 9.1 };
			int k = CountLess(a, 7, 3.0);          // менші 3: -1.2, -4.6, 2.9
			Assert::AreEqual(3, k);
		}
	};
}
