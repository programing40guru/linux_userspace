#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t lock;
int i;
int count=0;
void *mythread(void * avg){
	pthread_mutex_lock(&lock);
	for(int i=1;i<=9; i++)
	{
		count++;
		printf("count value =%d , and thread id = %ld\n",count,pthread_self()); 
	}

	pthread_mutex_unlock(&lock);

}

int main(){

	int err;
	if(pthread_mutex_init(&lock,NULL)!=0){
		printf("\n mutex init failed\n");
		return 1;
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
	pthread_mutex_destroy(&lock);
	return 0;

}
