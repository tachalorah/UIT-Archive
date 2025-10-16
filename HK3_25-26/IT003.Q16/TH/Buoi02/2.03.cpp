/*
 * 2.03: Điểm 3 chiều
 *
 * Cho một tập N điểm (x,y,z) trên không gian 3 chiều Oxyz. Bạn hãy sắp xếp và
 * in ra các điểm tăng dần theo x, nếu x bằng nhau thì sắp xếp các điểm giảm
 * dần theo y, nếu y bằng nhau thì sắp xếp các điểm tăng dần theo z.
 *
 * Cấm: (std::)sort, stable_sort, partial_sort, set, nth_element,
 *      priority_queue, sort_heap, multiset, map, multimap.
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

struct Point3D
{
	int XPos;
	int YPos;
	int ZPos;
};

bool Less(const Point3D &, const Point3D &);
void QuickSort(Point3D *, int, int);

int
main(void)
{
	int n;

	cin >> n;
	Point3D *a = new Point3D[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].XPos >> a[i].YPos >> a[i].ZPos;

	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i].XPos << " " << a[i].YPos
			<< " " << a[i].ZPos << "\n";
	delete[] a;
	return 0;
}

bool
Less(const Point3D &A, const Point3D &B)
{
	if (A.XPos < B.XPos)
		return true;
	if (A.XPos == B.XPos && A.YPos > B.YPos)
		return true;
	if (A.XPos == B.XPos && A.YPos == B.YPos && A.ZPos < B.ZPos)
		return true;
	return false;
}

void
QuickSort(Point3D *Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	int i = Begin, j = End;
	Point3D x = Array[Begin + (End - Begin) / 2];

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
