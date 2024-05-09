#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	int p[2],n;
	pid_t id;
	char buf;


	if(pipe(p)==-1){
		printf("no making pipe");
		exit(EXIT_FAILURE);
	}
else{
	id= fork();
	if(id==-1){
		printf("no makking fork ");
		exit(EXIT_FAILURE);
	}
	if(id == 0){ // child read from pipe
		close(p[1]); //close unuser write end 
		while((read(p[0],&buf,1)) > 0)
		{
			write(STDOUT_FILENO,&buf,1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(p[0]);
		exit(EXIT_SUCCESS);
		}

else 
{  //parent
	close(p[0]); // close unuserd read end 
	write(p[1], argv[1], strlen(argv[1]));
	close(p[1]); //
	wait(NULL); //wait for child 
	exit(EXIT_SUCCESS);


}
}
	return 0;
}
