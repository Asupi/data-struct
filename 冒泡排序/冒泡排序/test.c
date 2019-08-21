#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void BubbleSort(int array[], int size)
{
	int end = size;
	while (end - 1 > 0)
	{
		for (int i = 1; i < end; ++i)
		{
			if (array[i - 1] > array[i])
			{
				Swap(array + i - 1, array + i);
			}
		}
		end--;
	}
}

int main()
{

	int array[] = { 3, 6, 7, 2, 5, 4, 6, 15, 25 };
	int size = sizeof(array) / sizeof(int);
	PrintArray(array, size);
	BubbleSort(array, size);
	PrintArray(array, size);
	
	return 0;
}