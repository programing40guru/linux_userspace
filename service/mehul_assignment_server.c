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
#include <signal.h>

int main()
{

	char buf1[50] = {0};	 
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
	while(1){
		int  pid;
		char ndata[10];
		FILE *data= popen("pgrep cpro","r");
		fgets(ndata,5,data);
		pid=atoi(ndata);
		pclose(data);
		printf("%d\n",pid);

		valread= read(new_socket,buf1,10);
		buf1[valread] ='\0';
		printf("%s", buf1);		
		if (strcmp(buf1, "kill\n") == 0) {
			printf("system kill pro_service.service\n");
			//	scanf("%d",&k);
			int kk= kill(pid, SIGKILL);
			if(kk==0){
				printf("kill sucess"); 
			}else {
				printf("error .");
			}

		}

		if(valread == 0){
			close(new_socket);
			return 1;	
		}


	}	

	close(new_socket);
	close(id);
	return 0;
}
