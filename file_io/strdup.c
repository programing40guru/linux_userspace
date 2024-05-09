#include<stdio.h>
#include<string.h>

int main(){
	char data[]= "programming40guru";

	char * target= strndup(data,5);// copy of data is created dynamically
				    // and pointer to copy data
	if(target<0){
		printf("error copy data ");
	}
	else {
		printf("coped data : %s\n",target);
	}
	return 0;
}
