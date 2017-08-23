#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid;
pid=fork();
if(pid==-1)
printf("Error\n");
else if(pid==0)
{
execlp("/home/150905126/Desktop/D1-29/Lab4/first","./first",NULL);
}
else
{
wait(NULL);
printf("First completed\n");
exit(0);
}
}
