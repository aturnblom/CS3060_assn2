#include<stdio.h>
#include<unistd.h>
#include<sys/xattr.h>

int main(int argc, char *argv[]){
    printf("Before fork\n");
    int pid = fork();
    printf("After fork:%d\n",pid);
    if (pid==0){
        char *newargs[10];
        newargs[0] = "ls";
        newargs[1] = "-l";
        newargs[2] = "-a";
        newargs[3] = "NULL";
        printf("I am the child, ppid:%d, pid:%d\n", getppid(), getpid());
        execvp(argv[1], argv[1], NULL);
        perror("Well that didn't work");
    }
    else{
        print("I am the parent, ppid:%d, pid:%d\n", getppid(),getpid());
        wait(NULL);
        printf("Parent done waiting, time to exit\n")
    }
    return 0;
}
