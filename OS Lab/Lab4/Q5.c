#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
void main()
{
int fd;
fd=creat("file.txt",0777);
char msg[]="Hello World!";
//msg[strlen(msg)]='\0';
write(fd,msg,strlen(msg));
}
