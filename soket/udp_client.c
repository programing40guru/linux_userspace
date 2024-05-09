#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>


int main()
{
	char *buf;
	char * buf1;
	size_t valsend;
	size_t valread;
	struct sockaddr_in addr1;
	fd_set rfds;
	int retval;


	socklen_t p_frd= sizeof(addr1);

	buf = (char*)calloc(1000, sizeof(char));
	buf1 = (char*)calloc(1000, sizeof(char));

	int id = socket(AF_INET,SOCK_DGRAM,0); //creat a
	if(id<0){

		perror("socket failed and exit .. ");
		//exit(1);
	}

	addr1.sin_family=AF_INET;
	addr1.sin_port=htons(8080);
	//	addr1.sin_addr.s_addr=INADDR_ANY;
	addr1.sin_addr.s_addr = inet_addr("127.0.0.1"); 

	printf("connecting to....server \n");

	while(1){

		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(id, &rfds);
		retval=select(id+1,&rfds,NULL,NULL,NULL);
		if(FD_ISSET(0,&rfds)){


			printf("Mehul :");
			fgets(buf1,50,stdin);

			valsend =sendto(id,buf1,strlen(buf1),MSG_CONFIRM,(struct sockaddr *)&addr1,sizeof(addr1));
			if(sendto<0){
				printf("error send");
				exit(1);
			}
			memset(buf1,0,strlen(buf1));
			free(buf1);

		}
		if(FD_ISSET(id,&rfds)){


			valread=recvfrom(id, buf, sizeof(buf), MSG_WAITALL, (struct sockaddr*)&addr1,&p_frd);
			if(valread<0){
				printf("error rx");
				exit(1);
			}

			buf[valread]='\0';
			printf("Rahul -%s", buf);
			if(valread == 0){
				close(id);
				return 1;	
			}
			free(buf);

		}
	}
	close(id);

	return 0;
}

