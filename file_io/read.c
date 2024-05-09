#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){

	int fd,sz;
	//char file= "/sys/firmware/efi/runtime";
	char *c = (char *)calloc(100000,sizeof(char));
	fd =open("/usr/lib/avr/include/stdio.h",O_RDONLY);
	if(fd<0){
		perror("error openning file");
		exit(1);
	}
	else {
		printf("open file success\n");
	}
	sz= read(fd,c,100000);

	if(sz<0){
		perror("error reading file");
		exit(1);
	}

	c[sz] = '\0';
	printf("files data : %s\n", c);
	free(c);
	return 0;
}
