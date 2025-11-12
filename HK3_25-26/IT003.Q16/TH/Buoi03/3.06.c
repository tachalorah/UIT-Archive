#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#pragma GCC optimize("O3")

int 	BinarySearch(int *, int, int);
void 	QuickSort(int *, int, int);
void 	Swap(int *, int *);

int
main(void)
{
	int *arr = NULL;
	int arr_size, i, n, x;

	scanf("%d %d", &arr_size, &n);
	arr = (int *) malloc(arr_size * sizeof(int));
	for (i = 0; i < arr_size; i++)
		scanf("%d", &arr[i]);

	QuickSort(arr, 0, arr_size - 1);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (BinarySearch(arr, arr_size, x) == -1)
			puts("NO");
		else
			puts("YES");
	}
	return (0);
}

int
BinarySearch(int *Array, int Size, int x)
{
	int Left = 0, Right = Size - 1, Mid;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		if (x == Array[Mid])
			return (Mid);
		else if (x < Array[Mid])
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return (-1);
}

void
QuickSort(int *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int Mid = Array[Begin + (End - Begin) / 2];
	int i = Begin, j = End;

	while (i <= j)
	{
		while (i <= End && Array[i] < Mid)
			i++;
		while (j >= Begin && Mid < Array[j])
			j--;
		if (i <= j)
		{
			Swap(&Array[i], &Array[j]);
			i++;
			j--;
		}
	}

	QuickSort(Array, Begin, j);
	QuickSort(Array, i, End);
}

void
Swap(int *A, int *B)
{
	int tmp = *A;
	*A = *B;
	*B = tmp;
}
