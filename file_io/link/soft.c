#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/types.h>
int main(){

	int fd= open("sorignal.txt",O_CREAT|O_RDONLY,0666);
	if(fd<0){
		printf("no soring crited");

	}
	else {
              

               int e= unlink("/home/mehul/linux_user/file_io/link/slink.txt");
		int err=symlink("/home/mehul/linux_user/file_io/link/sorignal.txt","/home/mehul/linux_user/file_io/link/slink.txt");
		if(err<0){
			printf("erro no softlink created and soft link\n");
		}
		else {

			printf("sorignal.txt and slink.txt file crited softlink.\n");
		}

		close(fd);
		sleep(10);

		int err1= unlink("/home/mehul/linux_user/file_io/link/sorignal.txt");


		if(err1<0){
			printf("error unlink removing oringal soft \n");
		}
		else {
			printf("remove softlink convert softlink to deglink\n");
		}
	}
}

