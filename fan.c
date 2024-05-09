#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

for(int i=0; i<3;i++){
 if(fork()==0){
  printf("child id : %d and from the parent id = %d\n",getpid(),getppid());

exit(0);
}

}


}
