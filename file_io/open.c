#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int err;

	int fd = open("/sys/firmware/efi/runtime", O_RDONLY);

	printf("fd = %d\n", fd);

	if (fd == -1) {

		printf("Error types % d\n", errno);


		perror(" failure");
	}
	printf("success open file \n");

	err= close(fd);
	if(err==0){
		printf("file close. \n");
	}
	return 0;
}

