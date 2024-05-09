#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h> 

int main(){
char *args[]={"ls"}; // command 
char *env[]={0};
printf("run to  /bin/ls\n");

execve("/bin/ls",args,env);
perror("errore..");
exit(1);
}
