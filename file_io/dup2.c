/* int dup2(int oldfd, int newfd);
oldfd: old file descriptor
newfd new file descriptor which is used by dup2() to create a copy.
 */


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int file_des = open("file.txt",O_WRONLY,O_APPEND);
	if(file_des<0){
		printf("error openning the file\n");
	}
	else{
		// file new is the descriptor of strout 1
		int copy_des = dup2(file_des,1);

		if(copy_des<0){

			printf("error creating old file | 1 )out \n");
		}

		printf("i will be printed in this stdout  file file.txt\n");
	}
	close(file_des);
	return 0;
}
