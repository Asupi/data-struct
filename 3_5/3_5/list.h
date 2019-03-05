// 快速排序

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
	// 基准值是 array[right]

	while (begin < end) {
		// 优先走左边
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// 一定是左边卡住了

		// 再走右边
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// 一定是右边也卡住了

		Swap(array + begin, array + end);
	}

	// 区间被分成 小，大，基准
	Swap(array + begin, array + right);

	// 返回当前基准值所在位置
	return begin;
}

// 要排序的区间是 array[left, right]
void __QuickSort(int array[], int left, int right) {
	// 终止条件 size == 0 || size == 1
	// left == right	区间内还剩一个数
	// left > right		区间内没有数
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int div; // 比基准值小的放基准值左边，大的放右边后，基准值所在的下标
	div = Parition_1(array, left, right);	// 遍历 array[left, right]，把小的放左，大的放右
	__QuickSort(array, left, div - 1);	// 分治解决左边的小区间
	__QuickSort(array, div + 1, right);	// 分治解决右边的小区间
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
