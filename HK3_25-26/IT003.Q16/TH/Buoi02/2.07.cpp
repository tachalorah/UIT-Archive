/*
 * 2.07: Sắp xếp Chọn
 *
 * Hãy cài đặt thuật toán sắp selection sort để sắp xếp lại tăng dần mảng có N
 * phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra
 * mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được
 * cách hoạt động của thuật toán sắp xếp.
 */

#include <iostream>
using namespace std;

void SelectionSort(int *, int);

int
main(void)
{
	int n;

	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	SelectionSort(a, n);
	delete[] a;
	return 0;
}

void
SelectionSort(int *A, int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		if (i != min)
		{
			swap(A[i], A[min]);
			for (int k = 0; k < n; k++)
				cout << A[k] << (k == n - 1 ? "\n" : " ");
		}
	}
}
