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
	char buf[1024];
	struct sockaddr_in addr1;

	int id = socket(AF_INET,SOCK_STREAM,0); //creat an endpoint for communication
						//0 number o ip hendler 
						//	socklen_t p_frd = (sizeof(addr1));

	if(socket<0){

		perror("socket failed and exit .. ");
		//exit(1);
	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	//	addr1.sin_addr.s_addr=INADDR_ANY;

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
	printf("client say :hi \n");
	send(id,"hi",strlen("hi"),0);

	read(id,buf,1024-1);


	printf("server sayed %s\n",buf);
	//clossing socket


	close(id);

	return 0;
}
