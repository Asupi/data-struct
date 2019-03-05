// ��������

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
