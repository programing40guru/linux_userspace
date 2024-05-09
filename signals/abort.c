#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo){
	printf("Abort signal received!\n");

}

int main(void){
	int i=0;

	signal(SIGABRT, alarmHandler);

	while(1){
		if(getchar()=='P'){
			abort();
		}

	}
	pause();
	return 0;

}

