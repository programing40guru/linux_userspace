#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	struct stat sb;
	struct stat sb1;
	int fd1,sz1;
	int fd,sz;                                                
	fd =open("dup.txt",O_RDONLY,0666);
// fd =open("dup.txt",O_RDONLY,0666);


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
//	fd =open("dup.txt",O_RDONLY);

	fstat(fd,&sb1);

	char *c1 = (char *)calloc(sb1.st_size,sizeof(char));
	int dup1= dup(fd);
	sz1= read(dup1,c1,sb1.st_size);


	if(sz1<0){
		perror("error reading file");
		exit(1);
	}

	//c[sz] = '\0';
	printf("files data : %s\n", c1);

	close(fd);
	return 0;
}
