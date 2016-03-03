#include "stdafx.h"

extern "C"
{
#include "..\ShapeCCUtil\List.h"
}

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapeCCTest
{		
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(BasicListUsage)
		{
			ccList list;
			ccListInitDefault(&list, sizeof(int));
			ccListAdd(&list, (void*)24);
			ccListAdd(&list, (void*)32);
			ccListAdd(&list, (void*)((int)ccListGet(&list, 0) + (int)ccListGet(&list, 1)));
			Assert::AreEqual(24, (int)list.data[0], L"First add");
			Assert::AreEqual(32, (int)list.data[1], L"Second add");
			Assert::AreEqual(56, (int)list.data[2], L"Get and add");

			ccListClear(&list);
			Assert::AreEqual(0, (int)list.size, L"Clear");

			ccListDestroy(&list);
		}

		TEST_METHOD(ListResize)
		{
			ccList list;
			ccListInit(&list, 1, sizeof(int));
			ccListAdd(&list, (void*)24);
			ccListAdd(&list, (void*)32);
			Assert::AreEqual(24, (int)list.data[0], L"realloc 0 check");
			Assert::AreEqual(2, (int)list.size, L"resize 1 size check");
			Assert::AreEqual(2, (int)list.capacity, L"resize 1 capacity check");

			ccListAdd(&list, (void*)50);
			Assert::AreEqual(24, (int)list.data[0], L"realloc 0 check 2");
			Assert::AreEqual(3, (int)list.size, L"resize 2 size check");
			Assert::AreEqual(4, (int)list.capacity, L"resize 2 capacity check");

			ccListDestroy(&list);
		}
	};
}