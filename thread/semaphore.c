#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include <semaphore.h>

sem_t lock;
int i;
int count=0;
void *mythread(void * avg){
	sem_wait(&lock);
	for(int i=0;i<10; i++)
	{
		count++;
		printf("count value =%d , and thread id = %ld\n",count,pthread_self()); 
	}

	sem_post(&lock);

}

int main(){

	int err;
	err= sem_init(&lock,0,1);
	if(err!=0){
		printf("no  sem initilize  \n");

	}
	pthread_t pid,pid1;
	err= pthread_create(&pid,NULL,mythread,NULL);
	if(err!=0){
		printf("no thread 1 creat \n"); 
	}

	err= pthread_create(&pid1,NULL,mythread,NULL);
	if(err!=0){
		printf("no thread 1 creat \n"); 
	}
	pthread_join(pid,NULL);
	pthread_join(pid1,NULL);
	err= sem_destroy(&lock);
	if(err==0){
		printf("Thread SYNCHRONIZATION\n");
	}
	return 0;

}
