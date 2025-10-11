/*
 * 2.04: Tìm kiếm Nhị phân
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

int  BinarySearch(int *, int, int);
void QuickSort(int *, int, int);

int
main(void)
{
	int n, m, x;

	cin >> n >> m;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	QuickSort(a, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (BinarySearch(a, n, x) == -1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
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
BinarySearch(int *Array, int Size, int x)
{
	int Left = 0, Right = Size - 1, Mid;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		if (x == Array[Mid])
			return Mid;
		else if (x < Array[Mid])
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return -1;
}
