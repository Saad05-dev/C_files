#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

    pid_t pid_fils;
    int status;
    int desc[2];

    if (pipe(desc) == -1) {
        perror("pipe");
        return 1;
    }

    pid_fils = fork();
    
    if (pid_fils == -1) { 
        fprintf(stderr, "fork() impossible, errno=%d\n", errno);
        return 1;
    }

    if (pid_fils == 0) { 
        // Child process
        close(desc[1]);
         // Close the write end
        char ch;

        read(desc[0], &ch, sizeof(char));

        close(desc[0]); 
        // Close the read end
        printf("Received character: %c\n", ch);
    } else { 
        // Parent process
        close(desc[0]); 
        // Close the read end
        char ch;

        printf("Enter a character: ");
        scanf(" %c", &ch);

        write(desc[1], &ch, sizeof(char));
        close(desc[1]);
         // Close the write end
        waitpid(pid_fils, &status, 0); // Wait for child process
    }


return 0;
}