#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void *fun(){
	pthread_detach(pthread_self());// calling thread self
	printf("Inside the thread\n");

	sleep(2);
	printf("compalate  detached thread\n");

	pthread_exit(NULL); //exit current thread
}

int main(){

	pthread_t ptid;

	pthread_create(&ptid,NULL, &fun,NULL); //creat new thread   
	printf("before terminate thread \n");
	printf("continew.. thread...\n");
	sleep(3);

	// Compare the two threads created 
	if(pthread_equal(ptid, pthread_self())) 
		printf("Threads are equal\n"); 
	else
		printf("Threads are not equal\n"); 
	pthread_join(ptid, NULL); 
	printf("done all thraed.\n");


}
