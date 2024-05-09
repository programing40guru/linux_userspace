#include<stdio.h>
#include<unistd.h>//vfork
#include<sys/types.h>
int main(){

pid_t pid;
pid=vfork();
if(pid==0){
printf("child process start\n");
}
else if(pid>0){
printf("now comming back to parent process \n");
}



return 0;
}
