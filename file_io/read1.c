#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	struct stat sb;
	int fd,sz;
                                                         
	fd =open("/usr/lib/avr/include/stdio.h",O_RDONLY);


	if(fd<0){
		perror("error openning file");
		exit(1);
	}
	else {
		printf("open file success\n");
	}
 
	fstat(fd,&sb);

	char *c = (char *)calloc(sb.st_size,sizeof(char));
	sz= read(fd,c,sb.st_size);


	if(sz<0){
		perror("error reading file");
		exit(1);
	}

	c[sz] = '\0';
	printf("files data : %s\n", c);
        free(c);
	printf("total size= %ld\n",sb.st_size);


	return 0;
}
