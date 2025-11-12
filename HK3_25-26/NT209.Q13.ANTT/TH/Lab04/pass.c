#include <stdio.h>

int
main(void)
{
	char a[10] = "346348815", b[5] = "u2^#P", c[10];

	for (int i = 0; i < 9; i++) {
		if (i > 1)
			if (i > 3)
				c[i] = b[i - 4];
			else
				c[i] = a[i + 5];
		else
			c[i] = a[i + 2];
		c[i] = (c[i] + a[i]) / 2;
	}
	c[9] = 0;

	puts(c);
	return 0;
}
