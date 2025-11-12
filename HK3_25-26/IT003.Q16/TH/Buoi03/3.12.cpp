#include <stdio.h>
#include <unordered_map>

#pragma GCC optimize("O3")

struct Pos
{
	int First;
	int Last;
};

int
main(void)
{
	std::unordered_map<int, Pos> Map;
	int n, q, tmp, type;

	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (Map.count(tmp) == 0)
			Map[tmp] = {i + 1, i + 1};
		else
			Map[tmp].Last = i + 1;
	}

	for (int i = 0; i < q; i++)
	{
		scanf("%*s %d %d", &type, &tmp);
		if (Map.count(tmp) == 0)
			printf("-1\n");
		else if (type == 1)
			printf("%d\n", Map[tmp].First);
		else
			printf("%d\n", Map[tmp].Last);
	}
	return 0;
}
