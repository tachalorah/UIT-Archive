#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#pragma GCC optimize("O3")

struct Element
{
	std::string MaHang;
	size_t Count;
};

bool IsLess(const Element &, const Element &);
void QuickSort(std::vector<Element> &, int, int);

int
main(void)
{
	std::vector<Element> Arrec;
	std::vector<Element> Brrec;
	int j, n;

	std::cin >> n;
	if (n <= 0)
		return 0;
	Arrec.resize(n);
	for (Element &a: Arrec)
	{
		std::cin >> a.MaHang;
		a.Count = 0;
	}

	QuickSort(Arrec, 0, n - 1);
	Brrec.push_back(Arrec[0]);
	Brrec.back().Count = 1;

	j = 0;

	for (int i = 1; i < n; i++)
		if (Arrec[i].MaHang.compare(Arrec[i - 1].MaHang) == 0)
			Brrec[j].Count++;
		else
		{
			j++;
			Brrec.push_back(Arrec[i]);
			Brrec.back().Count = 1;
		}

	QuickSort(Brrec, 0, j);
	for (const Element &a: Brrec)
		std::cout << a.MaHang << " " << a.Count << "\n";

	Arrec.clear();
	Brrec.clear();
	return 0;
}

bool
IsLess(const Element &A, const Element &B)
{
	if (A.Count != B.Count)
		return A.Count > B.Count;
	if (A.MaHang.size() != B.MaHang.size())
		return A.MaHang.size() < B.MaHang.size();
	return A.MaHang < B.MaHang;
}

void
QuickSort(std::vector<Element> &Array, int Begin, int End)
{
	if (Begin >= End)
		return;

	Element Mid = Array[Begin + (End - Begin) / 2];
	int i = Begin, j = End;

	while (i <= j)
	{
		while (i <= End && IsLess(Array[i], Mid))
			i++;
		while (j >= Begin && IsLess(Mid, Array[j]))
			j--;
		if (i <= j)
		{
			std::swap(Array[i], Array[j]);
			i++;
			j--;
		}
	}

	QuickSort(Array, Begin, j);
	QuickSort(Array, i, End);
}
