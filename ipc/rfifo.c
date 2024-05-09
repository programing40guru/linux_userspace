#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	int fd1;
	
	char data1[80],data2[80];
                
while(1){              
	
	fd1= open("n1.txt",O_RDONLY);
    read(fd1,data1,80);



      printf("%s\n",data1);


	  close(fd1);

       }    
	
                
	return 0;
}
