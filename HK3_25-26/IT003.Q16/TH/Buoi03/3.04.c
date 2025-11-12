#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	bool *arr = NULL;
	int i, n, x;

	scanf("%d", &n);
	arr = (bool *) calloc((size_t)n + 1, sizeof(bool));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x >= 0 && x <= n)
			arr[x] = true;
	}

	for (i = 0; i <= n && arr[i] == true; i++)
		;

	printf("%d\n", i);
	free(arr);
	return (0);
}
