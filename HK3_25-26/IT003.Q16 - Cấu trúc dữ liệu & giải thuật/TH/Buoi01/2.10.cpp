/*
 * 2.10: Sắp xếp Trộn
 *
 * Hãy cài đặt thuật toán Merge Sort để sắp xếp không giảm mảng gồm N phần tử.
 * Trong quá trình merge, mỗi khi thực hiện thao tác trộn hai đoạn con, hãy in
 * ra cấu hình mảng sau khi thực hiện thao tác merge. Các đoạn đang được đã
 * thực hiện thao tác trộn được bao quanh bởi dấu [ ] để minh họa phạm vi đã
 * được merge.
 */

#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("O3")

/*
 * Lối chạy tuần tự - WeCode chấm sai 100%

void InMang(int *, int, int, int);
void MergeArray(int *, int, int, int);
void MergeSort(int *, int);

int
main(void)
{
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	MergeSort(a, n);
	delete[] a;
	return 0;
}

void
InMang(int *Array, int Size, int LPos, int RPos)
{
	for (int i = 0; i < Size; i++)
	{
		if (i == LPos)
			cout << "[ ";
		cout << Array[i];
		if (i == RPos)
			cout << " ]";
		if (i == Size - 1)
			cout << "\n";
		else
			cout << " ";
	}
}

void
MergeArray(int *Array, int LPos, int MPos, int RPos)
{
	int i, j, k;

	int Size_LM = MPos - LPos + 1,
	    Size_MR = RPos - MPos;

	int *Temp_LM = new int[Size_LM],
	    *Temp_MR = new int[Size_MR];

	for (i = 0; i < Size_LM; i++)
		Temp_LM[i] = Array[LPos + i];
	for (i = 0; i < Size_MR; i++)
		Temp_MR[i] = Array[MPos + i + 1];

	i = 0; j = 0; k = LPos;

	while (i < Size_LM && j < Size_MR)
		if (Temp_LM[i] <= Temp_MR[j])
			Array[k++] = Temp_LM[i++];
		else
			Array[k++] = Temp_MR[j++];
	while (i < Size_LM)
		Array[k++] = Temp_LM[i++];
	while (j < Size_MR)
		Array[k++] = Temp_MR[j++];

	delete[] Temp_LM;
	delete[] Temp_MR;
}

void
MergeSort(int *Array, int Size)
{
	if (Size <= 1)
		return;

	int LPos, MPos, RPos;

	for (int i = 1; i < Size; i *= 2)
		for (int j = 0; j < Size - i; j += 2 * i)
		{
			LPos = j;
			MPos = i + j - 1;
			RPos = min(2 * i + j - 1, Size - 1);
			MergeArray(Array, LPos, MPos, RPos);
			InMang(Array, Size, LPos, RPos);
		}
}
*/

/*
 * Lối đệ quy chia đôi, chạy ngon trên WeCode nhưng t đéo hiểu sao lại bắt
 * phải làm cách này. Nhưng, có điểm là được.
 */

void InMang(int *, int, int, int);
void MergeArray(int *, int, int, int);
void MergeSort(int *, int, int, int);

int
main(void)
{
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	MergeSort(a, n, 0, n - 1);
	delete[] a;
	return 0;
}

void
InMang(int *Array, int Size, int LPos, int RPos)
{
	for (int i = 0; i < Size; i++)
	{
		if (i == LPos)
			cout << "[ ";
		cout << Array[i];
		if (i == RPos)
			cout << " ]";
		if (i == Size - 1)
			cout << "\n";
		else
			cout << " ";
	}
}

void
MergeArray(int *Array, int LPos, int MPos, int RPos)
{
	int i, j, k;
	int Size_LM = MPos - LPos + 1,
	    Size_MR = RPos - MPos;
	int *Temp_LM = new int[Size_LM],
	    *Temp_MR = new int[Size_MR];

	for (i = 0; i < Size_LM; i++)
		Temp_LM[i] = Array[LPos + i];
	for (i = 0; i < Size_MR; i++)
		Temp_MR[i] = Array[MPos + i + 1];

	i = 0; j = 0; k = LPos;

	while (i < Size_LM && j < Size_MR)
		if (Temp_LM[i] <= Temp_MR[j])
			Array[k++] = Temp_LM[i++];
		else
			Array[k++] = Temp_MR[j++];

	while (i < Size_LM)
		Array[k++] = Temp_LM[i++];
	while (j < Size_MR)
		Array[k++] = Temp_MR[j++];

	delete[] Temp_LM;
	delete[] Temp_MR;
}

void
MergeSort(int *Array, int Size, int LPos, int RPos)
{
	if (LPos >= RPos)
		return;

	int MPos = LPos + (RPos - LPos) / 2;

	MergeSort(Array, Size, LPos, MPos);
	MergeSort(Array, Size, MPos + 1, RPos);
	MergeArray(Array, LPos, MPos, RPos);
	InMang(Array, Size, LPos, RPos);
}
