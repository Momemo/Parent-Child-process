//
//  cpipe.c
//  
//
//  Created by Mohammad Memon on 2/21/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

# define MSGSIZE 512
int main(){
    
    int fd[2];
    pid_t pid;
    char inbuf[MSGSIZE];

    // Pipe error read
    if (pipe(fd) == -1){
        
        perror("ERROR - Pipe");
        exit(1);
    }

    // Calls fork and puts in pid
    pid = fork();

    // Pid error read
    if(pid < 0)
    {
            perror("ERROR - Fork");
            exit(2);
    }
    // Child starts, writes in pipe, makes copy, closes, and executes pre.c
    else if(pid == 0)
    {
            close(1);
            dup(fd[1]);
            close(fd[0]);
            close(fd[1]);
            execl("./pre", "pre",(char *)0); // call execl() to execute pre.c
     }
     // Parent starts, reads from pipe, makes copy, closes, and executes sort.c
     else
     {
            close(0);
            dup(fd[0]);
            close(fd[0]);
            close(fd[1]);
            execl("./sort", "sort", (char *)0);
    }
    return(0);
}
