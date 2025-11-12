#include <stdio.h>
#include <stdlib.h>

#pragma GCC optimize("O3")

void InMang(int *, int, int, int);
void MergeArray(int *, int, int, int);
void MergeSort(int *, int, int, int);

int
main(void)
{
	int n;
	scanf("%d", &n);
	int *a = (int *) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	MergeSort(a, n, 0, n - 1);
	free(a);
	return 0;
}

inline void
InMang(int *Array, int Size, int LPos, int RPos)
{
	for (int i = 0; i < Size; i++)
	{
		if (i == LPos)
			printf("[ ");
		printf("%d", Array[i]);
		if (i == RPos)
			printf(" ]");
		if (i == Size - 1)
			printf("\n");
		else
			printf(" ");
	}
}

inline void
MergeArray(int *Array, int LPos, int MPos, int RPos)
{
	int i, j, k;
	int Size_LM = MPos - LPos + 1,
	    Size_MR = RPos - MPos;
	int *Temp_LM = (int *) malloc(Size_LM * sizeof(int)),
	    *Temp_MR = (int *) malloc(Size_MR * sizeof(int));

	for (i = 0; i < Size_LM; i++)
		Temp_LM[i] = Array[LPos + i];
	for (i = 0; i < Size_MR; i++)
		Temp_MR[i] = Array[MPos + i + 1];

	i = 0; j = 0; k = LPos;

	while (i < Size_LM && j < Size_MR)
		if (Temp_LM[i] <= Temp_MR[j])
			Array[k++] = Temp_LM[i++];
		else
			Array[k++] = Temp_MR[j++];

	while (i < Size_LM)
		Array[k++] = Temp_LM[i++];
	while (j < Size_MR)
		Array[k++] = Temp_MR[j++];

	free(Temp_LM);
	free(Temp_MR);
}

void
MergeSort(int *Array, int Size, int LPos, int RPos)
{
	if (LPos >= RPos)
		return;

	int MPos = LPos + (RPos - LPos) / 2;

	MergeSort(Array, Size, LPos, MPos);
	MergeSort(Array, Size, MPos + 1, RPos);
	MergeArray(Array, LPos, MPos, RPos);
	InMang(Array, Size, LPos, RPos);
}

