#include "pch.h"

// ���������[�N�̃L���v�`��
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CppUnitTest.h"
#include "../include/omp_test.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_CLEANUP(test_module_cleanup) {
		Assert::IsFalse(_CrtDumpMemoryLeaks());// ���������[�N�`�F�b�N
	}


	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			const int NUM_X = 16384;
			const int NUM_Y = 16384;
			int* a[NUM_Y];
			for (int y = 0; y < NUM_Y; y++) {
				a[y] = (int*)malloc(NUM_X * sizeof(int));
				for (int x = 0; x < NUM_X; x++) {
					a[y][x] = rand();// �����ŏ�����
				}
			}

			// ���C�u�����ŏ���
			long long sum[NUM_Y];
			add_array(sum, a, NUM_X, NUM_Y);

			// �茳�Ōv�Z���Ĕ�r
			for (int y = 0; y < NUM_Y; y++) {
				long long s = 0;
				for (int x = 0; x < NUM_X; x++) {
					s += a[y][x];
				}

				Assert::AreEqual(sum[y], s);
			}

			// ���������
			for (int y = 0; y < NUM_Y; y++) {
				free(a[y]);
			}
		}
	};
}
