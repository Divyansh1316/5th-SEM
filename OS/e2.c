#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
    int size,se=0,so=0;
    printf("Enter size : ");
    scanf("%d",&size);
    
    int arr[size];
    
    printf("Enter size : ");
    for(int i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }
    
    pid_t p=fork();
    if(p<0)
    {
      printf("fork failed");
    }
    else if(p==0)
    {
       for(int i=0;i<size;i++)
      {
        if(arr[i]%2!=0)
        {
          so+=arr[i];
        }
      }
      printf("Child process with id : %d\n",getpid());
      printf("Sum of odd numbers : %d\n",so);
    }
    else
    {
      for(int i=0;i<size;i++)
      {
        if(arr[i]%2==0)
        {
          se+=arr[i];
        }
      }
      printf("Parent process with id : %d\n",getpid());
      printf("Sum of even numbers : %d\n",se);
    }
}
