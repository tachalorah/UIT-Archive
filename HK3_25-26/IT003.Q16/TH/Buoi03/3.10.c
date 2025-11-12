#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *, int, int);
void Swap(int *, int *);
int  LowerBound_Sorted(int *, int, int);

int
main(void)
{
	int *arr = NULL;
	int bound, n, q, target;

	scanf("%d %d", &n, &q);
	arr = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	QuickSort(arr, 0, n - 1);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &target);
		bound = LowerBound_Sorted(arr, n, target);
		if (bound == -1)
			printf("-1\n");
		else
			printf("%d\n", arr[bound]);
	}
	free(arr);
	return (0);
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

inline void
Swap(int *A, int *B)
{
	int tmp = *A;
	*A = *B;
	*B = tmp;
}

int
LowerBound_Sorted(int *Array, int Size, int Target)
{
	if (Array[Size - 1] < Target)
		return (-1);

	int Left = 0, Right = Size - 1, Mid;

	while (Left < Right)
	{
		Mid = Left + (Right - Left) / 2;
		if (Array[Mid] >= Target)
			Right = Mid;
		else
			Left = Mid + 1;
	}

	if (Left < Size && Array[Left] < Target)
		Left++;
	return Left;
}
