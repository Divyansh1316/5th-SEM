//orphan process

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
      printf("child process\n");
      sleep(5);
      printf("child became orphan\n");
      printf("child id and new parent id : %d %d\n",getpid(),getppid());
    }
    else
    {
      printf("parent process : %d\n",getpid());
      exit(0);
    }
}
