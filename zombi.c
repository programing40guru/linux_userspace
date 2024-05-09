#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){

pid_t child= fork();
if(child>0){  // parent process
sleep(50);


}
else {

exit(0); // child process 

}
return 0;

}
