#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

int main(int avg , char *file[]){

	int fd;
	fd= open(file[1],O_WRONLY|O_CREAT|O_TRUNC|O_RDONLY,0644);
	if(fd<0){
		printf("error opening file\n");
	}
	int len = tee(0,1,INT_MAX,0);
	if(len <0){
		printf("error nofree");
		return 1;
	}
	printf("free size = %d",len);

 int slen = splice(0,NULL,fd,NULL,len,0);
if(slen <0){
                  printf("error no splce ");
                  return 1;
          }
  printf("splice size = %d",slen);

}
