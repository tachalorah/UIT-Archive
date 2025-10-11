/*
 * 2.08: Sắp xếp Nổi bọt
 *
 * Hãy cài đặt thuật toán tìm kiếm nổi bọt để sắp xếp lại mảng có N phần tử.
 * Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau
 * hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt
 * động của thuật toán sắp xếp.
 */

#include <iostream>
using namespace std;

#pragma GCC optimize("O3")

void BubbleSort(int *, int);

int
main(void)
{
	int n;

	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	BubbleSort(a, n);
	delete[] a;
	return 0;
}

void
BubbleSort(int *A, int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
				swapped = true;
				for (int k = 0; k < n; k++)
					cout << A[k] <<
						(k == n - 1 ? "\n" : " ");
			}
		}
		if (!swapped)
			break;
	}
}
