#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

struct foo(){
	int a,b,c,d;
};
void *mythread(){

	struct foo foo= {1,2,5,8};
        printfoo(&foo);
        thread_exit((void *)&foo);

}

void printfoo(struct foo *st){
printf("printng thread struct a = %d",st->a);

}



int main(){
	int err;
	pthread_t tid1,tid2;
    void * l=NULL;
	struct foo  *p;
	err= pthread_create(&tid1,NULL,mythread1,NULL);
	if(err==0){
		printf(" 1 thread created");
	}
	pthread_join(tid1,&l);

}
