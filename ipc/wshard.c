#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main(){
       
	int semid;
        int i=0;
       char data[100];
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

	printf("write data :");
	fgets(str,1024,stdin);

    
	printf("writed data :%s",str);

	int err1 = shmdt(str);
	if(err1<0){
		printf("error detache..");
		exit(1);
	}
	return 0;

}
