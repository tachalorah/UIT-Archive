#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int XPos;
	int YPos;
	int ZPos;
}
Point3D;

bool Less(const Point3D *, const Point3D *);
void QuickSort(Point3D *, int, int);
void Swap(Point3D *, Point3D *);

int
main(void)
{
	Point3D *arr = NULL;
	int arr_size, i;

	scanf("%d", &arr_size);
	arr = (Point3D *) malloc(arr_size * sizeof(Point3D));
	for (i = 0; i < arr_size; i++)
		scanf("%d %d %d", &arr[i].XPos, &arr[i].YPos, &arr[i].ZPos);

	QuickSort(arr, 0, arr_size - 1);
	for (i = 0; i < arr_size; i++)
		printf("%d %d %d\n", arr[i].XPos, arr[i].YPos, arr[i].ZPos);
	return (0);
}

bool
Less(const Point3D *A, const Point3D *B)
{
	if (A->XPos < B->XPos)
		return (true);
	if (A->XPos == B->XPos && A->YPos > B->YPos)
		return (true);
	if (A->XPos == B->XPos && A->YPos == B->YPos && A->ZPos < B->ZPos)
		return (true);
	return (false);
}

void
QuickSort(Point3D *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	Point3D Mid = Array[Begin + (End - Begin) / 2];
	int i = Begin, j = End;

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

inline void
Swap(Point3D *A, Point3D *B)
{
	Point3D tmp = *A;
	*A = *B;
	*B = tmp;
}
