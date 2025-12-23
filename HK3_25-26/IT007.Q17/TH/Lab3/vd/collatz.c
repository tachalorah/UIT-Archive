#include <sys/mman.h>
#include <sys/wait.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	long long *ptr, num;

	if (argc < 2)
		errx(0, "Cách dùng: %s <số nguyên dương>", argv[0]);
	num = atoll(argv[1]);
	if (num < 1)
		errx(1, "%lld bé hơn 1, thoát.", num);
	ptr = mmap(0, sizeof(long long) * 4096, PROT_READ | PROT_WRITE,
	    MAP_SHARED | MAP_ANON, -1, 0);
	if (ptr == MAP_FAILED)
		err(2, "mmap");

	switch (fork()) {
	case -1:
		err(3, "fork");
	case 0:
		ptr[0] = num;
		for (int i = 1; num > 1 && i < 4096; i++) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = 3 * num + 1;
			ptr[i] = num;
		}
		exit(0);
	default:
		wait(NULL);
		for (int i = 0; ptr[i] >= 1 && i < 4096; i++)
			printf("%lld%s", ptr[i], (ptr[i] == 1) ? "\n" : ", ");
	}
	munmap(ptr, sizeof(long long) * 4096);
	return 0;
}
