#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <netinet/in.h>
#include <string.h>


int main()
{

	char buf1[10]= {0};
	
	struct sockaddr_in addr1;
	ssize_t valread;
	//	char data[1024];

	fd_set rfds;
	int retval;
	int id = socket(AF_INET,SOCK_STREAM,0); //creat an endpoint for communication

	if(id<0){

		perror("socket failed and exit .. ");

	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	addr1.sin_addr.s_addr=INADDR_ANY;

	int s=inet_pton(AF_INET,"127.0.0.1",&addr1.sin_addr);
	if(s<=0){
		perror("\n invalid address\n");
		exit(EXIT_FAILURE);

	}

	int c=connect(id,(struct sockaddr *)&addr1,sizeof(addr1));
	if(c<0){
		perror("\n connection faild..\n");
		exit(EXIT_FAILURE);

	}
	printf("connecting to....server \n"); 
             while(1){  
			fgets(buf1,10,stdin);
			send(id,buf1,strlen(buf1),0);
			


}
	
			
	return 0;
}
