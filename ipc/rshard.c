#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	int semid;
        int i=0;
	key_t key = ftok("shmfile",40);
	//identifier of the System V shared memory segment
	int id= shmget(key,1024,0664|IPC_CREAT);
	//key, storage , flag 

	if(id<0){
		printf("no system allocate shared memory \n");
		exit(0);
	}

	printf("key of shared memory ..%d\n",id);

	char *str= (char *)shmat(id,NULL,0);
	if (str == (void *) -1){
		exit(1);
	}
	printf("process at memory %p\n",str);
 
	printf("readed data :%s",str);



int err1 = shmdt(str);
	if(err1<0){
		printf("error detache..");
		exit(1);
	}
	printf("5 second to distroid memory data\n");
	sleep(3);
	//Mark the segment to be destroyed
	int err= shmctl(id,IPC_RMID,0);
	if(err<0){

		printf("no distroed data ");

	}
	
	return 0;

}
