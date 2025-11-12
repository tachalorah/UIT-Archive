#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int XPos;
	int YPos;
}
Point;

bool Less(const Point *, const Point *);
void QuickSort(Point *, int, int);
void Swap(Point *, Point *);

int
main(void)
{
	Point *arr = NULL;
	int arr_size, i;

	scanf("%d", &arr_size);
	arr = (Point *) malloc(arr_size * sizeof(Point));
	for (i = 0; i < arr_size; i++)
		scanf("%d %d", &arr[i].XPos, &arr[i].YPos);

	QuickSort(arr, 0, arr_size - 1);
	for (i = 0; i < arr_size; i++)
		printf("%d %d\n", arr[i].XPos, arr[i].YPos);
	return 0;
}

bool
Less(const Point *A, const Point *B)
{
	if (A->XPos < B->XPos)
		return true;
	if (A->XPos == B->XPos && A->YPos > B->YPos)
		return true;
	return false;
}

void
QuickSort(Point *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int i = Begin, j = End;
	Point Mid = Array[Begin + (End - Begin) / 2];

	while (i <= j)
	{
		while (i <= End && Less(&Array[i], &Mid))
			i++;
		while (j >= Begin && Less(&Mid, &Array[j]))
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
Swap(Point *A, Point *B)
{
	Point tmp = *A;
	*A = *B;
	*B = tmp;
}
