#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.3/lab6.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63
{
	TEST_CLASS(UnitTest63)
	{
	public:
		// 1 2 3 4 5 -> 2 1 4 3 5 (останній елемент лишається на місці)
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1, 2, 3, 4, 5 };
			int expected[] = { 2, 1, 4, 3, 5 };
			SwapPairs(a, 5);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(expected[i], a[i]);
		}
	};
}
