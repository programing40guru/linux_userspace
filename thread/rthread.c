#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
void *myThread(void *ret)
{
	*(int *)ret +=8;

	return (void *)ret;

}

int main()
{
	pthread_t tid;
	int a=2;
	int err;
	void *status =&a;

	void *ptr;

	err=pthread_create(&tid, NULL, myThread,status);
	if(err!=0){
		printf("no thread create "); exit(0);

	}
	pthread_join(tid, &ptr);
	//a=*(int *)ptr;

	printf("%d\n",*(int *)ptr);    

	return 0;
}
