#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#pragma GCC optimize("O3")

bool IsLess(char **, char **);
bool IsEqual(char **, char **);
void QuickSort(char **, int, int);
void Swap(char **, char **);

int
main(void)
{
	char **arr = NULL;
	bool *brr = NULL;
	int m, n;

	scanf("%d", &n);
	arr = (char **) malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char *) malloc(101 * sizeof(char));
		scanf("%s", arr[i]);
	}

	QuickSort(arr, 0, n - 1);

	m = 1;
	for (int i = 1; i < n; i++)
		if (!IsEqual(&arr[i], &arr[i - 1]))
			m++;

	printf("%d\n", m);

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	free(brr);
	return (0);
}

void
QuickSort(char **Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int i = Begin, j = End;
	char *x = Array[Begin + (End - Begin) / 2];

	while (i <= j)
	{
		while (i <= End && IsLess(&Array[i], &x))
			i++;
		while (j >= Begin && IsLess(&x, &Array[j]))
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

bool
IsLess(char **A, char **B)
{
	return (strncmp(*A, *B, 101) < 0);
}

bool
IsEqual(char **A, char **B)
{
	return (strncmp(*A, *B, 101) == 0);
}

void
Swap(char **A, char **B)
{
	char *tmp = *A;
	*A = *B;
	*B = tmp;
}
