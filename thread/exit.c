#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
void * mythread1(){

	printf("running 1 thread \n");
	sleep(1);
	return( (void *)1);
}
void * mythread2(){


	sleep(1);
	printf("exiting  2  \n");

	pthread_exit((void *)2);
}


int main(){

	int err;
	pthread_t tid1,tid2;
	void *tt;	
	err= pthread_create(&tid1,NULL,mythread1,NULL);
	if(err==0){
		printf("created  thread 1  \n");
	}
	err= pthread_create(&tid2,NULL,mythread2,NULL);
	if(err==0){
		printf("created  thread 2  \n");
	}


	pthread_join(tid1,&tt);
	printf("thread 1 is done \n");
	pthread_join(tid2,&tt);
	printf("thread 2 is done \n");
}
