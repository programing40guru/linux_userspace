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

	char * buf;
	char *buf1;
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

	buf = (char*)calloc(1024, sizeof(char));
	buf1 = (char*)calloc(1024, sizeof(char));

	while(1){


		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(id, &rfds);

		retval=select(id+1,&rfds,NULL,NULL,NULL);
		if(FD_ISSET(0,&rfds)){
		       
                  	printf("Mehul :");
			fgets(buf1,50,stdin);
			send(id,buf1,strlen(buf1),0);
			
	memset(buf1,0,strlen(buf1));


		}
		if(FD_ISSET(id,&rfds)){


			valread= read(id,buf,50);


			buf[valread] = '\0';
			if(valread == 0){
				close(id);
				return 1;
			}
			printf("rahul - %s",buf);
		memset(buf,0,strlen(buf));	
		}		

	}	

	
	free(buf);
	free(buf1);

	return 0;
}
