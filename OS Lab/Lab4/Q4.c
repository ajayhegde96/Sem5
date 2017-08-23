#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid=fork();
if(pid==0)
{
printf("Child starting\n");
printf("Child completed\n");
exit(0);
}
else
{
printf("Parent starting\n");
sleep(5);
printf("Parent completed\n");
}
}
