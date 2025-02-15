#include <stdio.h>
#include <unistd.h>

int main(){

    __pid_t pid;
    __pid_t ppid;


    int k = fork();

    pid = getpid();
    ppid = getppid();

    
    printf("pid= %d -> ppid= %d ,fork= %d\n",(long)pid,(long)ppid,k);

    return 0;
}