#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.2/lab6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
	TEST_CLASS(UnitTest62)
	{
	public:
		// масив 5, -3, 8, 0, 8, -3, 2:
		// перший максимум 8 має індекс 2, перший мінімум -3 має індекс 1
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 5, -3, 8, 0, 8, -3, 2 };
			int s = SumIndexMaxMin(a, 7);
			Assert::AreEqual(3, s);
		}
	};
}
