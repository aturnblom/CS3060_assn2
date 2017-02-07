#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
//Allison Noot
//CS3060-001 Spring 2017
//Assignment 2
/* Promise of Originality
I promise that this source code file has, in its entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

int main(int argc, char *argv[]){
    int pid = fork();

    if (pid == 0){
        char *newargs[argc];

        int i;
        for (i = 0; i < argc; i++){
            newargs[i] = argv[i + 1];
        }
        if(argc == 1){
            printf("CHILD started, no arguments provided. Terminating child\n");

        }
        else if(argc == 2){
            printf("CHILD started, One argument provided. Calling execlp()\n");
            execlp(argv[1], argv[1], NULL);
            perror("Well that didn't work");
        }
        else{
            printf("CHILD started, More than one argument provided. Calling excevp()\n");
            execvp(argv[1], newargs);
            perror("Well that didn't work");
        }

//        printf("I am the child, ppid:%d, pid:%d\n", getppid(), getpid());



    }
    else{
        printf("PARENT started, now waiting for process %d\n", pid);
//        printf("I am the parent, ppid:%d, pid:%d\n", getppid(),getpid());
        wait(NULL);
        if(WIFEXITED(NULL)){
          const int returnStat = WEXITSTATUS(NULL);
          printf("PARENT resumed. Child exit code of %d. Now terminating parent\n", returnStat);
        }


    }
    return 0;
}
