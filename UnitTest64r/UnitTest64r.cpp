#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4r/lab6.4r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64r
{
	TEST_CLASS(UnitTest64r)
	{
	public:
		// масив 3.7, -1.2, 10.0, 8.5, -4.6, 2.9, 9.1 (n = 7)
		TEST_METHOD(TestMethod1)
		{
			double a[] = { 3.7, -1.2, 10.0, 8.5, -4.6, 2.9, 9.1 };
			int k = CountLess(a, 7, 3.0, 0);       // менші 3: -1.2, -4.6, 2.9
			Assert::AreEqual(3, k);
		}
	};
}
