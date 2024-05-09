#include<stdio.h>

#include<signal.h>
void handler(int sig )
{
printf("child process terminated\n");
}

int main()
{
pid_t pid;
signal(SIGCHLD,handler);
pid= fork();
if(pid == 0){
printf("this is child process\n");
sleep(3);
}

if(pid > 0){
printf("this is parent process\n");
wait(NULL);
}
}
