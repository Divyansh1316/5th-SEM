//FIFO or named pipe
//writer process

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
    char str[100];
    int fd,nbw;
    mknod("myfifo",S_IFIFO|0666,0);
    printf("Writing for writer process\n");
    fd=open("myfifo",O_WRONLY);
    while(gets(str))
    {
      nbw=write(fd,str,strlen(str));
      printf("Writes %d bytes %s\n",nbw,str);
    }
}
