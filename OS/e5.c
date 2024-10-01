#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
    char arr[100],str[100];
    int fd[2],nbr,nbw;
    
    pipe(fd);
    
    pid_t p=fork();
    if(p<0)
    {
      printf("fork failed");
    }
    else if(p==0)
    {
      nbr=read(fd[0],arr,sizeof(arr));
      arr[nbr]='\0';
      printf("\nChild read %d bytes %s\n",nbr,arr);
      
    }
    else
    {
      printf("Enter a string : ");
      gets(str);
      nbw=write(fd[1],str,strlen(str));
      printf("\nParent write %d bytes %s\n",nbw,str);
    }
}
