#pragma once

#include <stdio.h>
#include<stdlib.h>
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// ��������
// ʱ�临�Ӷ�:
// 1) ���		O(n)	�Ѿ�����
// 2) ƽ��		O(n^2)
// 3) �		O(n^2)	�Ѿ�����������
// �ռ临�Ӷ�
// O(1)
// �ȶ�
void InsertSort(int array[], int size) {
	// ��ߵ�ѭ��ʵ�ּ��ι���
	// һ��ȡһ���������뵽ǰ�������������
	// ���Ż��İ汾
	// for (int i = 1; i < size; i++) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		// �ڲ���ѭ��ʵ�ֵ��ǲ���Ĺ���
		// j �� [i-1, 0]
		// ��� array[j] > key�������
		// ��� array[j] == key������ѭ������֤���ȶ��ԣ�
		// ��� array[j] < key������ѭ��
		int j;
		for (j = i - 1; j >= 0 && array[j] > key; j--) {
			array[j + 1] = array[j];
		}

		// j + 1 ����Ҫ�����λ��
		array[j + 1] = key;
	}
}

// ϣ������
// �ǲ���������Ż��汾
// �ڲ�������֮ǰ�������ܵ�����������
// �������
// ʱ�临�Ӷ�
// 1�����	O(n)
// 2��ƽ��	O(n^1.2) - O(n^1.3)
// 3�����	O(n^2)
// �ռ临�Ӷ�
// O(1)
// ���ȶ���һ�����飬���ѱ�֤��ͬ���ֵ�һ�����

// �������� gap �Ĳ�������
void InsertSortWithGap(int array[], int size, int gap) {
	// ���Ż��İ汾Ӧ����
	// for (int i = gap; i < size; i++) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		for (j = i - gap; j >= 0 && array[j] > key; j -= gap) {
			array[j + gap] = array[j];
		}

		array[j + gap] = key;
	}
}

void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = (gap / 3) + 1;	// ����������û�о�������
		InsertSortWithGap(array, size, gap);
		if (gap == 1) {
			return;
		}
	}
}

// ѡ������
// ʱ�临�Ӷȣ�
// ���/ƽ��/�	O(n^2)
// �ռ临�Ӷ� O(1)
// ���ȶ� { 9, 4, 3, 5a, 5b }���޷���֤ 5a һ���� 5b ǰ
void SelectSort(int array[], int size) {
	// for (int i = 0; i < size - 1; i++) {
	for (int i = 0; i < size; i++) {
		int max = 0;	// �����������±�Ϊ 0
		for (int j = 1; j < size - i; j++) {
			if (array[j] > array[max]) {
				max = j;
			}
		}

		Swap(array + max, array + size - 1 - i);
	}
}

// �����򣨽���ѣ�
// ʱ�临�Ӷȣ�
// ���|ƽ��|�	O(n*log(n))
// �ռ临�Ӷ� O(1)
// ���ȶ�	�����µ��������У��޷���֤�����ǰ���ϵ��
// ���µ���
// ʱ�临�Ӷ� O(log(n))
void AdjustDown(int array[], int size, int root)
{
	int i = 2 * root + 1;
	int j = 2 * root + 2;

	if (i >= size) {
		return;
	}

	int m = i;
	if (j < size && array[j] > array[i]) {
		m = j;
	}

	if (array[m] > array[root]) {
		Swap(array + m, array + root);
		AdjustDown(array, size, m);
	}
}
// ����
// O(n) or O(n * log(n))
void CreateHeap(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}
// ������
void HeapSort(int array[], int size)
{
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		Swap(array, array + size - i - 1);
		AdjustDown(array, size - 1 - i, 0);
	}
}

// ʱ�临�Ӷ�
// ��� O(n)	�Ѿ�����
// �|ƽ�� O(n^2)
// �ռ临�Ӷ� O(1)
// �ȶ�
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int sorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				sorted = 0;
			}
		}
		if (sorted == 1) {
			return;
		}
	}
}

// ��������

int Parition_1(int array[], int left, int right) {
	int begin = left;
	int end = right;
	// ��׼ֵ�� array[right]

	while (begin < end) {
		// ���������
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// һ������߿�ס��

		// �����ұ�
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// һ�����ұ�Ҳ��ס��

		Swap(array + begin, array + end);
	}

	// ���䱻�ֳ� С���󣬻�׼
	Swap(array + begin, array + right);

	// ���ص�ǰ��׼ֵ����λ��
	return begin;
}

// Ҫ����������� array[left, right]
void __QuickSort(int array[], int left, int right) {
	// ��ֹ���� size == 0 || size == 1
	// left == right	�����ڻ�ʣһ����
	// left > right		������û����
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int div; // �Ȼ�׼ֵС�ķŻ�׼ֵ��ߣ���ķ��ұߺ󣬻�׼ֵ���ڵ��±�
	div = Parition_1(array, left, right);	// ���� array[left, right]����С�ķ��󣬴�ķ���
	__QuickSort(array, left, div - 1);	// ���ν����ߵ�С����
	__QuickSort(array, div + 1, right);	// ���ν���ұߵ�С����
}

void QuickSort(int array[], int size) {
	__QuickSort(array, 0, size - 1);
}

void Test() {
	int array[] = { 3, 4, 9, 8, 7, 11, 12, 4, 5, 1, 0, 2, 6 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	QuickSort(array, size);
	PrintArray(array, size);
}

int main() {
	Test();
	system("pause");
}