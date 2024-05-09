#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <netinet/in.h>
#include <string.h>

/*
   struct sockaddr_in {
   sa_family_t    sin_family; // address family: AF_INET 
   in_port_t      sin_port;   // port in network byte order 
   struct in_addr sin_addr;   // internet address 
   };


   struct sockaddr {
   sa_family_t sa_family;
   char        sa_data[14];
   }


 */
int main()
{
	struct sockaddr_in addr1;

	int id = socket(AF_INET,SOCK_STREAM,0); //creat an endpoint for communication
						//0 number o ip hendler 
	socklen_t p_frd = (sizeof(addr1));

	if(socket<0){

		perror("socket failed and exit .. ");
		//exit(1);
	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	addr1.sin_addr.s_addr=INADDR_ANY;

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
	printf("hello i am server ..\n");
	printf("connectting success to client \n");
	ssize_t valread;
	char buffer [100];
	valread = read(new_socket, buffer,100 - 1); // subtract 1 for the null
						    // terminator at the end
	printf("client sayed :");
	printf("%s\n", buffer);
	printf("server say :hello \n");
	send(new_socket,"hello", strlen("hello"), 0);
	//	printf("Hello message sent to client \n");

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	close(id);

	return 0;
}
