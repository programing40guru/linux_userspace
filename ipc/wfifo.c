#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
int main(){

	int fd;
	mkfifo("n1.txt",0666); //creat file fifo
	char data1[80],data2[80];

while(1){
                 printf("you are user 1 say ...\n");
		fd= open("n1.txt",O_WRONLY);
		fgets(data1,80,stdin); // get input from data 1
		write(fd,data1,strlen(data1));
		close(fd);

	}
	return 0;

}
