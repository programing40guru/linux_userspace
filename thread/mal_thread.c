#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void * mythread(void *avg){

	printf("thread 1  are criated\n");
	sleep(3);

	return NULL;
}

void * mythread1(void *avg){

	printf("thread 2  are criated\n");
	sleep(3);

	return NULL;
}


int main(){

	int err;
	pthread_t pid1,pid2;

	printf("heyy one bye one thread criating....\n");
       sleep(2);
	err= pthread_create(&pid1,NULL,mythread,NULL);
	if(err!=0){
		printf("no thread 1 creat \n");
		exit(0); 
	}
	sleep(3);

	pthread_join(pid1,NULL);
	if(err!=0){

		printf("no finishing thread 1\n");
		exit(0);
	}
	else {

		printf("thread 1 are done . \n");

	}


	pthread_create(&pid2,NULL,mythread1,NULL);
	if(err!=0){

		printf("no creat thread 2\n");
	}

         
           sleep(3);

	err=pthread_join(pid2,NULL);
           
	if(err!=0){

		printf("no finishing thread 2\n");
	}
	else {

		printf("thread 2 are done . \n");
		exit(0);
	}

}
