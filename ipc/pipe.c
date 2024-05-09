#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){

	int p[2];
	pid_t id;

	char mgs[]="hell";
	char buf[strlen(mgs)];


	if(pipe(p)<0){
		printf("no making pipe");
		exit(1);
	}

	else {

		printf("now maked pipe write pipe ...\n");
	}


	int err=write(p[1],mgs,strlen(mgs));
	if(err<0){
		printf("no data write \n");
	}     else {

		printf("success data write ...");
	}
	read(p[0],buf,strlen(mgs));
	printf("data is :%s\n",buf);

	return 0;
}
