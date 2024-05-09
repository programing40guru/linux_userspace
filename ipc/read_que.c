#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <pthread.h>
#include <stdlib.h>
#include<unistd.h>
struct mgs_data{ 
	long type; 
	char data[100];
}mgs;

void *read_q(void *p)
{
	key_t key; 
	int mgsid; 
	key = ftok("profile", 65);  // procest id and project file
	if(key<0){
		printf("no gerate key ");
	}

	//  mgs to cfete icp
	mgsid = msgget(key+1, 0666 | IPC_CREAT); 

	if(mgsid<0){
		printf("no mgs quire identi ");
	}

	while(1){

		int err2=msgrcv(mgsid, &mgs, sizeof(mgs), 1, 0);
		if(err2<0){
			printf("no recive mgs\n");
		}
		printf("Data Received is : %s",mgs.data);
	}	
}

void *write_q(void *p)
{
	key_t key; 
	int mgsid; 


	// ftok to unice key genrate
	key = ftok("profile", 65);  // procest id and project file
	if(key<0){
		printf("no gerate key ");
	}
	mgs.type = 1;
	//  mgs to cfete icp
	mgsid = msgget(key, 0666 | IPC_CREAT); 

	if(mgsid<0){
		printf("no mgs quire identi ");
	}
	while(1){	
		printf("Write Data : "); 
		fgets(mgs.data,10,stdin); 

		// msgsnd to send message 


		int err1= msgsnd(mgsid, &mgs, sizeof(mgs), 0); // id , mgs data size and flage  

		if(err1<0){
			printf("no  mgs send ");
		}

	}
}


int main() 
{ 

	pthread_t id1,id2;
	int err;

	err=pthread_create(&id2, NULL,read_q,NULL);
	if(err!=0)
	{
		printf("thread not created\n");
		exit(0);
	}

	err=pthread_create(&id1, NULL,write_q,NULL);
	if(err!=0)
	{
		printf("thread not created\n");
		exit(0);
	}



	pthread_join(id1,NULL);
	pthread_join(id2,NULL);

	exit(0);

}

