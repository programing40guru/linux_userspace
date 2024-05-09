#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include<sys/types.h> 
#include<unistd.h>
void *calls(void *avg) 
{ 

	sleep(1); 
	printf("hello mehul in function\n"); 
	return NULL; 
} 

int main() 
{

	int  err;
	pthread_t thread; // declare thread identifire

	err=  pthread_create(&thread, NULL, calls,NULL); 
       if(err!=0){
         printf("no thread created error\n ");
         exit(0);
       }
	printf("thread id = %ld\n",(long) thread);  
	
//	int *ptr=NULL; 

	pthread_join(thread,NULL);  

	printf("created thread succ\n");

	return 0; 
}
