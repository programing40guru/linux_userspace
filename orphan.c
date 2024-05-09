#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){

int pid = fork();
if(pid>0){

printf("in parent processs1\n");
 

}
else if(pid==0){
sleep(30);
printf("in child process");

}
return 0;
}
