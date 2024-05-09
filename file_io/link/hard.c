#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/types.h>
int main(){

	int fd= open("horignal.txt",O_CREAT|O_RDONLY,0666);
	if(fd<0){
		printf("no horing crited");

	}
	else {
               
                unlink("/home/mehul/linux_user/file_io/link/hlink.txt");

		int err= link("/home/mehul/linux_user/file_io/link/horignal.txt","/home/mehul/linux_user/file_io/link/hlink.txt");
		if(err<0){
			printf("erro no hardlink created and harg link\n");
		}
		else {

			printf("horignal.txt and hlink.txt file crited hardlink.\n");
		}

		close(fd);
		sleep(10);

		int err1= unlink("/home/mehul/linux_user/file_io/link/horignal.txt");


		if(err1<0){
			printf("error unlink removing oringal hard file \n");
		}
		else {
			printf("remove hard link convert hard link to deglink\n");
		}
	}

}
