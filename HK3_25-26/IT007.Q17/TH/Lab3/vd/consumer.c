#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SHM_NAME "/SHM"
#define SHM_SIZE 10

int
main(void)
{
	int *ptr, fd, tmp, sum;

	do {
		fd = shm_open(SHM_NAME, O_RDWR, 0600);
		if (fd == -1)
			usleep(500000);
	} while (fd == -1);
	ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
		err(3, "mmap");

	sum = 0;
	while (sum <= 100) {
		tmp = *ptr;
		sum += tmp;
		printf("%d, sum = %d\n", tmp, sum);
		if (sum > 100)
			*ptr = -1;
		usleep(500000);
	}

	if (munmap(ptr, SHM_SIZE) == -1)
		err(4, "munmap");
	if (close(fd) == -1)
		err(5, "close");
	if (shm_unlink(SHM_NAME) == -1)
		err(6, "shm_unlink");
	return 0;
}
