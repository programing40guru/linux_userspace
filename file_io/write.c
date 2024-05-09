#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int sz, err;
	char data[]= "hello programming40guru \nits new 1 text file. okay\n";
//	int fd= open("nn.txt",O_WRONLY |O_CREAT|O_TRUNC);
    int fd= open("new1.txt",O_WRONLY |O_CREAT|O_TRUNC,644);

	if(fd<0){
		perror("error openning file");
		exit(1);
	}
	else {
		printf("success file open\n");
	}
	sz= write(fd,data,strlen(data));
	if(sz>=0){
		printf("file write success writing. data :%s\n",data);
	}
	printf("array of char %d\n",sz);
	err= close(fd);
	if(err==0){
		printf("cloce success\n");
	}
	close(fd);
}
