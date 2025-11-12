/* bắt đầu template */
#include <iostream>
#include <vector>
using namespace std;
/* kết thúc template */

#pragma GCC optimize("O3")

void QuickSort(int *, int, int);
int  StevesGift_sorted(int *, int, int);

int
main(void)
{
	int *a = NULL;
	int max, n;

	cin >> n >> max;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	QuickSort(a, 0, n - 1);
	cout << StevesGift_sorted(a, n, max) << "\n";
	delete[] a;
	return 0;
}

void
QuickSort(int *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int i = Begin, j = End;
	int x = Array[Begin + (End - Begin) / 2];

	while (i <= j)
	{
		while (i <= End && Array[i] < x)
			i++;
		while (j >= Begin && x < Array[j])
			j--;
		if (i <= j)
		{
			swap(Array[i], Array[j]);
			i++;
			j--;
		}
	}

	QuickSort(Array, Begin, j);
	QuickSort(Array, i, End);
}

int
StevesGift_sorted(int *Array, int Size, int Limit)
{
	int Left = 0, Right = Size - 1, Sum = 0, Temp;

	while (Left < Right)
	{
		Temp = Array[Left] + Array[Right];
		if (Temp > Limit)
			Right--;
		else
		{
			if (Temp > Sum)
				Sum = Temp;
			Left++;
		}
	}
	return Sum;
}

