#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        printf("Child pid = %d\n",getppid());
        exit(0);
    }
    else{
        wait(0);
        printf("Parent pid = %d\n",getpid());
        printf("Child pid = %d\n",pid);
    }

    return 0;
}
