#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.2r/lab6.2r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62r
{
	TEST_CLASS(UnitTest62r)
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
