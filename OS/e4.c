//zombie process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
    pid_t p=fork();
    if(p<0)
    {
      printf("fork failed");
    }
    else if(p==0)
    {
      printf("child id and parent id : %d %d\n",getpid(),getppid());
      exit(0);
    }
    else
    {
      printf("parent process : %d\n",getpid());
      sleep(10);
      printf("Check process table for zombie process");
    }
}
