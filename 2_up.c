#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("HC: hello from child\n");		
		//printf("child id  : %d\n",getpid());
		printf("parent id  : %d\n",getppid());
	}
	else
	{
		kill();
		printf("HP: hello from parent\n");
		printf("parent id : %d\n",getpid());
		printf("Child id : %d\n",pid);
		//wait(NULL);
		printf("CT: child has terminated\n");		

	}
	printf("Bye\n");		
	return 0;
}
