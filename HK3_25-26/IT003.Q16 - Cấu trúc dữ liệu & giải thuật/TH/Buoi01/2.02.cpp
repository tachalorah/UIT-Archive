/*
 * 2.02: [Sorting] điểm 2 chiều (Template)
 *
 * Tương tự 2.01 nhưng không được dùng một số tính năng có sẵn.
 *
 * Cấm: (std::)sort, stable_sort, partial_sort, set, nth_element,
 *      priority_queue, sort_heap, multiset, map, multimap.
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

struct Point
{
	int XPos;
	int YPos;
};

bool Less(const Point &, const Point &);
void QuickSort(Point *, int, int);

int
main(void)
{
	int n;

	cin >> n;
	Point *a = new Point[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].XPos >> a[i].YPos;

	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i].XPos << " " << a[i].YPos << "\n";
	delete[] a;
	return 0;
}

bool
Less(const Point &A, const Point &B)
{
	if (A.XPos < B.XPos)
		return true;
	if (A.XPos == B.XPos && A.YPos > B.YPos)
		return true;
	return false;
}

void
QuickSort(Point *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int i = Begin, j = End;
	Point x = Array[Begin + (End - Begin) / 2];

	while (i <= j)
	{
		while (i <= End && Less(Array[i], x))
			i++;
		while (j >= Begin && Less(x, Array[j]))
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
