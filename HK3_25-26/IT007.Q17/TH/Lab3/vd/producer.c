#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SHM_NAME "/SHM"
#define SHM_SIZE 10

int
main(void)
{
	int *ptr, fd, tmp;

	fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);
	if (fd == -1)
		err(1, "shm_open");
	if (ftruncate(fd, SHM_SIZE) == -1)
		err(2, "ftruncate");
	ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
		err(3, "mmap");

	srand(time(NULL));
	while (*ptr != -1) {
		*ptr = 10 + rand() % 11;
		usleep(500000);
	}

	if (munmap(ptr, SHM_SIZE) == -1)
		err(4, "munmap");
	if (close(fd) == -1)
		err(5, "close");
	return 0;
}
