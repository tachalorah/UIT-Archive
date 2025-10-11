/*
 * 2.09: Sắp xếp Chèn
 *
 * Hãy cài đặt thuật toán sắp xếp chèn để sắp xếp lại tăng dần mảng có N phần
 * tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap (dời phần tử hoặc
 * gán phần tử mới vào vị trí thích hợp), hãy in ra mảng sau hành động swap đó.
 * Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán
 * sắp xếp.
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

void InsertionSort(int *, int);
void InMang(int *, int);

int
main(void)
{
	int n;

	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	InsertionSort(a, n);
	delete[] a;
	return 0;
}


void
InMang(int *A, int n)
{
	for (int j = 0; j < n; j++)
		cout << A[j] << (j == n - 1 ? '\n' : ' ');
}

void
InsertionSort(int *A, int n)
{
	for (int i = 1; i < n; i++)
	{
		int e = A[i];
		int k = i - 1;
		while (k >= 0 && A[k] > e)
		{
			A[k + 1] = A[k];
			k--;
			InMang(A, n);
		}
		A[k + 1] = e;
		InMang(A, n);
	}
}
