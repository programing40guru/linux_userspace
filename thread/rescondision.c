#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int i;
 int count=0;
void *mythread(void *avg)
{
	for(int i=0;i<8; i++)
	{
		count++;
		printf("count value =%d , and thread id = %ld\n",count,pthread_self()); 
	}
}

int main()
{
	int err;

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
	printf ("total count value is = %d\n",count);
	printf("okayy\n");

}
