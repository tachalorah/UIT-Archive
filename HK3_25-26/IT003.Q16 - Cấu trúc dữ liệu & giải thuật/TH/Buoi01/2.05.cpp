/*
 * 2.05: Tìm kiếm Nhị phân: điểm 3D
 *
 * Hãy viết chương trình nhập vào một danh sách A gồm tọa độ n điểm trong không
 * gian 3 chiều đã được sắp xếp tăng dần theo giá trị chiều x, nếu giá trị
 * chiều x bằng nhau thì xét tăng dần theo giá trị chiều y, nếu giá trị chiều y
 * bằng nhau thì xét tăng dần theo giá trị chiều z. Sau đó, nhập m điểm pi và
 * kiểm tra bằng thuật toán tìm nhị phân xem các điểm pi này có xuất hiện trong
 * danh sách A hay không.
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

bool IsEqual(const Point3D &, const Point3D &);
bool Less(const Point3D &, const Point3D &);
int  BinarySearch(Point3D *, int, Point3D);

int
main(void)
{
	int m, n, ret;
	Point3D x;

	cin >> n;
	Point3D *a = new Point3D[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].XPos >> a[i].YPos >> a[i].ZPos;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x.XPos >> x.YPos >> x.ZPos;
		ret = BinarySearch(a, n, x);
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
BinarySearch(Point3D *Array, int Size, Point3D x)
{
	int Left = 0, Right = Size - 1, Mid,
	    i = 0;

	while (Left <= Right)
	{
		i++;
		Mid = Left + (Right - Left) / 2;
		if (IsEqual(x, Array[Mid]))
			return i;
		if (Less(x, Array[Mid]))
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return -1;
}
