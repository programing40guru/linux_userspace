#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handle_sigint(int sg){
} 

int main(){

signal(SIGINT,handle_sigint); // signal innit signal hendler
	
	while(1){
		printf("hello mehul\n");
		sleep(1);

	}
	return 0;
}
