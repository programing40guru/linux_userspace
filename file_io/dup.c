#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){

	int file_des =open("dup.txt",O_WRONLY);
	char old[]= "this will be output to the file name dup.txt\n";
	char new[]="this will be slo output to the file name dup.txt\n";

	if(file_des<0){
		printf("error openning the file\n");
	}

	int copy_des= dup(file_des);

	if(copy_des<0){
		printf("error creating old file | 1 )out \n");
	}
	else{
		write(copy_des,old,strlen(old));
		write(file_des,new,strlen(new));
	}
        close(file_des);
	return 0;

}
