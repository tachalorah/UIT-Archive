/*
 * 2.01: [Sorting] điểm 2 chiều (STL)
 *
 * Cho một tập N điểm (x,y) trên mặt phẳng Oxy. Bạn hãy sắp xếp và in ra các
 * điểm tăng dần theo x, nếu x bằng nhau thì sắp xếp các điểm giảm dần theo y.
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

int
main(void)
{
	int n;

	cin >> n;
	Point *a = new Point[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].XPos >> a[i].YPos;

	sort(a, a + n, Less);
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
