#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handal_signal(int sg){

	alarm(1);
	printf("ok boss 1 secong terminated program %d.\n",sg);


}
int main(){

	signal(SIGINT,handal_signal);
	int i=0;
	while(1){
		printf("hello still working signals...\n");
		//	alarm(1);
		sleep(1);
		i++;
	}

}
