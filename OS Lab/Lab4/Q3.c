#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid;
pid=fork();
switch(pid)
{
case -1:printf("Error\n");
	break;
case 0:printf("CHILD\n");
	printf("ID %d\n",getpid());
       printf("Parent ID %d\n",getppid());
	break;
default:printf("PARENT\n");
	printf("ID %d\n",getpid());
	wait(NULL);
	printf("ID of parent of parent %d\n",getppid());
	break;
}
}
