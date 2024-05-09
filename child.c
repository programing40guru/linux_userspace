#include<stdio.h> //printf
#include<stdlib.h>  // exit()
#include<sys/types.h>  //pid_t
#include <unistd.h>  //fork()
#include<sys/wait.h> // wait()
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("its is the child process and pid is =%d\n",getpid());
		int i=0;
		for(int i=0;i<5;i++){
			printf("%d\n",i);
		}
		exit(0);
	}

	else if(pid>0){
		printf("its is the parent  process and pid is =%d\n",getpid());
		int status;
		wait(&status);
		printf("child is reped\n");
	}
	return 0;
}
