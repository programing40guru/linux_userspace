#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <netinet/in.h>
#include <string.h>
#include<sys/select.h>


int main()
{

	char * buf;
	char * buf1;
	struct timeval tv;
	ssize_t valread;

	struct sockaddr_in addr1;
	fd_set rfds;
	int retval;


	int id = socket(AF_INET,SOCK_STREAM,0); //creat an endpoint for communication
						//0 number o ip hendler 
	socklen_t p_frd = (sizeof(addr1));

	if(id<0){

		perror("socket failed and exit .. ");
		exit(EXIT_FAILURE);
	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	addr1.sin_addr.s_addr=INADDR_ANY;//targeted interface make

	if((bind(id,(struct sockaddr *)&addr1,sizeof(addr1))) == -1){

		perror("Bind failed and exit ..");
		exit(EXIT_FAILURE);
	}

	if (listen(id, 4) < 0){    //listen 4 connection
		perror("listen");
		exit(EXIT_FAILURE);
	}

	int new_socket;// accept a connection
	if ((new_socket = accept(id, (struct sockaddr*)&addr1, &p_frd))< 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	printf("hello i am seirver ..\n");
	printf("connectting success to client \n");
	buf = (char*)calloc(50, sizeof(char));
	buf1 = (char*)calloc(50, sizeof(char));

	while(1){
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(new_socket, &rfds);

		retval=select(new_socket+1,&rfds,NULL,NULL,NULL);
		if(FD_ISSET(new_socket,&rfds)){
 	
	valread= read(new_socket,buf1,50);		
			buf1[valread] = '\0';
			if(valread == 0){
				close(new_socket);
				return 1;	
			}
			printf("mehul -%s", buf1);
			memset(buf1,0,strlen(buf1));
		

		}
		if(FD_ISSET(0,&rfds)){

			
			
			printf("Rahul :");
			fgets(buf,50,stdin);
			send(new_socket,buf, strlen(buf), 0);
				
         memset(buf,0,strlen(buf));

		}
	}
	free(buf);
	free(buf1);


	close(new_socket);
	close(id);
	return 0;
}
