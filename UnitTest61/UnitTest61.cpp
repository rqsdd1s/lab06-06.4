#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.1/lab6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		// масив 10, 3, 4, 7, 8, 12, 9, 14, 6:
		// критерій виконують r[2]=4, r[4]=8, r[5]=12, r[8]=6
		TEST_METHOD(TestMethod1)
		{
			int r[] = { 10, 3, 4, 7, 8, 12, 9, 14, 6 };
			int k = Count(r, 9);
			Assert::AreEqual(4, k);
		}
	};
}
