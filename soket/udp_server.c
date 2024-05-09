#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<pthread.h>
#include<sys/select.h>

int main(){

	int new_socket;
	char *buf;
	char *buf1;

	pthread_t thread_id[10];

	buf = (char*)calloc(50, sizeof(char));
	buf1 = (char*)calloc(50, sizeof(char));

	ssize_t valread;
	ssize_t valsend;

	struct sockaddr_in addr1,addr2;
	socklen_t p_frd= sizeof(addr1);

	int id= socket(AF_INET,SOCK_DGRAM,0);
	if(id<0){
		perror("socket failed and exit .. ");
	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	addr1.sin_addr.s_addr=INADDR_ANY;//targeted interface 

	if((bind(id,(struct  sockaddr *)&addr1,sizeof(addr1)))<0){
		perror("Bind failed and exit ..");
		exit(EXIT_FAILURE);
	}


	printf("hello i am server ..\n");
	printf("connectting success to client \n");
	printf("Enter message ");
	while(1){

	
		printf("Mgs Client PORT: %d\n",ntohs(addr1.sin_port));
/*inet_ntoa(addr1.sin_addr)); ntohs(addr1.sin_port)*/

		fd_set rfds;
		int retval;
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(id, &rfds);

		retval=select(id+1,&rfds,NULL,NULL,NULL);
		if(FD_ISSET(id,&rfds)){


			valread=recvfrom(id, buf, sizeof(buf), MSG_WAITALL, (struct sockaddr*)&addr1,&p_frd);
			if(valread<0){
				printf("error rx");
				exit(1);
			}

			buf[valread]='\0';
			printf("mehul -%s", buf);
                            
                              if(valread == 0){
				close(id);
				return 1;	
			}

		}
		if(FD_ISSET(0,&rfds)){


			printf("Rahul :\n");
			fgets(buf1,50,stdin);
			valsend =sendto(id,buf1,strlen(buf1),MSG_CONFIRM,(struct sockaddr *)&addr1,sizeof(addr1));
			if(sendto<0){
				printf("error send");
				exit(1);
			}
			memset(buf1,0,strlen(buf1));


		}

	}
	free(buf1);
        free(buf);
	return 0;
}

