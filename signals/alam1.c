#include <stdio.h>
#include <unistd.h>
#include <signal.h>

 void alarmHandler(int signo){
	printf("Alarm signal sent!\n");

}

int main(void){
	int i=0;
	alarm(5);

	signal(SIGALRM, alarmHandler);

	for(int i=1;i<6;i++){
		printf(" %d \n",i);
		sleep(1);    
	}
	pause();
	return 0;

}

