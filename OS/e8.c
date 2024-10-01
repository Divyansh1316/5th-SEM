#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void forkTree(int depth)
{
  if(depth<=0)
  {
    return;
  }
  pid_t left,right;
  left=fork();
  if(left<0)
  {
    printf("Fork failed");
  }
  if(left==0)
  {
    printf("Left child with pid %d, parent pid %d\n",getpid(),getppid());
    forkTree(depth-1);
    exit(0);
  }
  
  right=fork();
  if(right<0)
  {
    printf("Fork failed");
  }
  if(right==0)
  {
    printf("right child with pid %d, parent pid %d\n",getpid(),getppid());
    forkTree(depth-1);
    exit(0);
  }
  wait(NULL);
  wait(NULL);
}
int main()
{
  int depth=2;
  printf("Parent process with pid %d\n",getpid());
  forkTree(depth);
}
