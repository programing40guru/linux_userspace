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

int i=0;
  
  int    fd = open("data.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU|S_IRWXG|S_IRWXO); 
if(fd<0){
		perror("error openning file");
		exit(1);
	}	
 key_t key = ftok("s",40);
	  key_t key1 = ftok("s",40);
	//identifier of the System V shared memory segment
	int id= shmget(key,1024,0666|IPC_CREAT);
	//key, storage , flag 

	if(id<0){
		printf("no system allocate shared memory \n");
		exit(0);
	}

	 

	char *str= shmat(id,NULL,0);
	if (str == (char *) -1){
		printf("error momory");
		exit(1);
	} 

	int idn=semget(key1, 1, IPC_CREAT | 0666);
	if(idn<0){
		printf("error no identifire semaphore");
		exit(0);
	}


	arg.val=1;
	//initialize semaphore 0 is set value 1
	int c= semctl(id,0,SETVAL,arg);
	if(c<0){
		printf("error controll pration ");
	}

		printf("shmid = %d; semid = %d\n", id, idn);
		// Wait semaphore value to 0
		printf("at process.. %p\n",str); 
               
               sop.sem_num = 0;
		sop.sem_op = -1;
		sop.sem_flg = 0;
		
		
               if (semop(idn, &sop, 1) == -1){
		     printf("error");
		    
		}
   printf("write data ");
 while(i<2){
        fgets(str,1024,stdin);

 int sz= write(fd,str,strlen(str));
i++;
}	     
		sop.sem_num = 0;
		sop.sem_op = 1;
		sop.sem_flg = 0;

		//signal are to read process read... 
		if (semop(idn, &sop, 1) == -1){
			exit(1);
		}



		//detace memory
		int err1 = shmdt(str);
		if(err1<0){
			printf("error detache..");
			exit(1);
		}


 
     printf("Writer process: Clean up complete.\n");


	

	//detach
	//Remove shared memory and semaphore

	return 0;
}
