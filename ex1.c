#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <math.h>
#include <sys/types.h>


int main(){
    
    pid_t pid_fils;
    int status;
    int desc[2];


    if(pipe(desc) == -1){
        perror("Pipe failed");
        return 1;
    }

    pid_fils = fork();

    if(pid_fils==0){

        close(desc[1]);

        int res;

        read(desc[0],&res,sizeof(int));

        close(desc[0]);

        printf("double = %d \n",res*2);


    }else{

        close(desc[0]);

        int x;


        printf("saisir x: ");
        scanf("%d",&x);    

        write(desc[1],&x,sizeof(int));

        close(desc[1]);

        waitpid(pid_fils,&status,0);

    }
    return 0;
}