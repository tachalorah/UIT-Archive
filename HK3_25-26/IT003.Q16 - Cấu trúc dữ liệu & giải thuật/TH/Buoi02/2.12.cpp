/*
 * 2.12: Tìm tuyến tính: Tìm điểm 3D
 *
 * Hãy viết chương trình nhập vào một danh sách A gồm tọa độ n điểm trong không
 * gian 3 chiều. Sau đó, nhập m điểm pi và kiểm tra xem các điểm pi này có xuất
 * hiện trong danh sách A hay không.
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

struct Point3D
{
	float XPos;
	float YPos;
	float ZPos;
};

bool Less(const Point3D &, const Point3D &);
bool IsEqual(const Point3D &, const Point3D &);
int  LinearSearch(Point3D *, int, const Point3D &);

int
main(void)
{
	int n, m, ret;
	Point3D x;

	cin >> n;
	Point3D *a = new Point3D[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].XPos >> a[i].YPos >> a[i].ZPos;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x.XPos >> x.YPos >> x.ZPos;
		ret = LinearSearch(a, n, x);
		if (ret == -1)
			cout << "KHONG\n";
		else
			cout << ret << "\n";
	}
	delete[] a;
	return 0;
}

bool
Less(const Point3D &A, const Point3D &B)
{
	if (A.XPos < B.XPos)
		return true;
	if (A.XPos == B.XPos && A.YPos < B.YPos)
		return true;
	if (A.XPos == B.XPos && A.YPos == B.YPos && A.ZPos < B.ZPos)
		return true;
	return false;
}

bool
IsEqual(const Point3D &A, const Point3D &B)
{
	if (A.XPos != B.XPos)
		return false;
	if (A.YPos != B.YPos)
		return false;
	if (A.ZPos != B.ZPos)
		return false;
	return true;
}

int
LinearSearch(Point3D *Array, int Size, const Point3D &A)
{
	for (int i = 0; i < Size; i++)
		if (IsEqual(Array[i], A))
			return i;
	return -1;
}
