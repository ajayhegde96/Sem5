#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
void main()
{
int fd1,fd2;
fd1=open("file.txt",O_RDWR);
char msgs[1000]={'\0'};
read(fd1,msgs,sizeof(msgs));
//printf("%s",msgs);
fd2=creat("file2.txt",0666);
write(fd2,msgs,strlen(msgs));
}

