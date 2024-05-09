#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <netinet/in.h>
#include <string.h>
#include<pthread.h>
#include<sys/select.h>

void *client(void *arg) {
	int id = *(int*)arg;
	char buf1[1000]={0};
	char buf[1000]={0};
	ssize_t valread;
	fd_set rfds;

	while(1){
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(id, &rfds);
		
                select(id+1,&rfds,NULL,NULL,NULL);
		if(FD_ISSET(id,&rfds)){
			valread = read(id,buf,50); 
                        if(valread <= 0){
			
				break;
			}
			buf[valread] = '\0';
                        
			printf("mehul -%s", buf);
                        
			memset(buf,0,strlen(buf));
		}
		if(FD_ISSET(0,&rfds)){

			
			fgets(buf1,50,stdin);

			send(id,buf1, strlen(buf1), 0);
			memset(buf1,0,strlen(buf1));
		}
	}
	printf("disconnect ..\n");
	close(id);
	pthread_exit(NULL);
}


int main()
{

	int new_socket;
	
	ssize_t valread;
	struct sockaddr_in addr1;
	pthread_t thread_id[10];

	int id = socket(AF_INET,SOCK_STREAM,0); //creat an endpoin						//0 number o ip hendler 
	socklen_t p_frd = (sizeof(addr1));
	int i=0;
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

	while(1){

		if ((new_socket = accept(id, (struct sockaddr*)&addr1, &p_frd))< 0) {
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(addr1.sin_addr), ntohs(addr1.sin_port));

	if (pthread_create(&thread_id[i++], NULL, client, (void *)&new_socket) < 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
		if (i >= 10) {
			i = 0;
			// Wait for all threads to finish
			for (int j = 0; j < 10; j++) {
				pthread_join(thread_id[j], NULL);
			}
		}
	}

	return 0;
}

