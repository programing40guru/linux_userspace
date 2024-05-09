#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
int main(){

	struct dirent *dd; // make pointer for directory enty

	DIR *dir = opendir(".");// return dir stype stuct pointer 

	if(dir==NULL){
		printf("do note open dir\n");
		return 0;
	}
	while((dd=readdir(dir))!=NULL){

		printf("name is %s ",dd->d_name);

		printf("file types : %d ",dd->d_type);

		printf("lenth of recode = %d ",dd->d_reclen);
		//   printf("%ld",dd->d_off);
		printf("file info %ld\n",dd->d_ino);

		printf("\n----------------\n ");
	}


	return 0;
}
