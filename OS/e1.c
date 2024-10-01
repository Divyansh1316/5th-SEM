#include<stdio.h>
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
      printf("child process : %d parent id : %d\n",getpid(),getppid());
    }
    else
    {
      printf("parent process : %d\n",getpid());
      wait(NULL);
      printf("child process terminated pid of child : %d\n",p);
    }
}
