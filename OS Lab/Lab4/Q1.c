#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
int s;
pid_t pid;
pid=fork();
if(pid==-1)
printf("Error\n");
else if(pid==0)
{
for(int i=0;i<3;i++)
printf("Child process\n");
exit(0);
}
else
{
wait(&s);
printf("Parent process\n");
printf("Child returned with status %d\n",s);
}
}

