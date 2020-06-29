//
//  unixcmnd.c
//  
//
//  Created by Mohammad Memon on 2/24/20.
//

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

//argc and argv are parameters to pass linux commands, argv hold the commands
//argc holds the number
int main(int argc, char* argv[])
{
    // Variables
    int pid;
    int childpid;

    // Calling and getting process and putting in pid to determine where to go
    pid = fork();

    // If process is less than 0, we know it failed. Child 0, parent > 0
    if(pid < 0)
    {
        printf("ERROR - Fork failed");
    }

    // Child process (know by being 0)
    else if(pid == 0)
    {
        printf("Child starting...\n");
        printf("Command is %s \n\n", argv[1]);

        // Printing the output of the command passed as a command line argument
        system(argv[1]);

        printf("\n\n");
    }

    // Parent process is positive, and will hit if its not 0 or less
    else
    {
        printf("Parent is waiting for child to finish...");

        // Waiting for child to stop
        sleep(4);

        // Waits until child process is done,
        // and if successful returns child process id
        int status = 0;
        childpid = wait(&status);

        printf("\nChild has finished...");
        printf("\n\n");

        // Printing the pid of the parent and child process
        printf("Child's pid, %d and parent's id, %d.\n", getpid(), getppid());
        printf("Parent has finished...");
    }
        return 0;
}
