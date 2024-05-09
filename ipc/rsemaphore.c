#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include <sys/shm.h>
#include<unistd.h>
#include <string.h>
#include<fcntl.h>
#include <sys/stat.h>
#define SIZE 1024

union semun {
	int    val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	//struct seminfo  *__buf;  /* Buffer for IPC_INFO

};


int main(){

	union semun arg;
	struct sembuf sop;
	char str[1024],str1[1024];

	int i=0;

	int    fd = open("data.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU|S_IRWXG|S_IRWXO); 
	if(fd<0){
		perror("error openning file");
		exit(1);
	}	
	key_t key1 = ftok("sr",50);

	int idn=semget(key1, 1, IPC_CREAT | 0666);
	if(idn<0){
		printf("error no identifire semaphore");
		exit(0);
	}


	arg.val=0;
	//initialize semaphore 0 is set value 1
	int c= semctl(idn,0,SETVAL,arg);
	if(c<0){
		printf("error controll pration ");
	}

	// Wait semaphore value to 0
	printf("at process.. %p\n",str); 

	sop.sem_num = 0;
	sop.sem_op = -1;
	sop.sem_flg = 0;


	if (semop(idn, &sop, 1) == -1){
		printf("error");
		exit(1);
	}
	printf("read data");
int sz=read(fd,str,1024);
             printf("read data shared memory: %s\n", str);
	     
	sop.sem_num = 0;
	sop.sem_op = 1;
	sop.sem_flg = 0;

	//signal are to read process read... 
	if (semop(idn, &sop, 1) == -1){
		exit(1);
	}

	close(fd);

	printf("Writer process: Clean up complete.\n");




	//detach
	//Remove shared memory and semaphore

	return 0;
}
