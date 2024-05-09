#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handle_sigint(int sig) 
{ 
	printf("Caught signal %d\n", sig); 
} 

int main(){
int i=0;
        printf("ushing handler function create function ..\n.");
	signal(SIGINT, handle_sigint); 
	while (i<5) 
	{ 
		printf("hello world\n"); 
		sleep(1); 
                i++;
	} 
	pid_t id=getpid();
        printf("id = %d\n",id);
	sleep(2);
	printf("okk now terminate try ushing kill\n ");
 kill(id,SIGINT);

	while(1){

		printf(" hello mehul\n");
		
             //   kill(id,SIGINT);
                sleep(1);
	}
 
	return 0;

}
