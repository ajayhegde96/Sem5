#include <stdio.h>
#include <pthread.h>
int fib[100];
void* child_thread(void* param)
{
int n= (int) param;
fib[0]=0;
fib[1]=1;
for(int i=2;i<n;i++)
{
	fib[i]=fib[i-1]+fib[i-2];
}
}

void main()
{
	pthread_t thread;
	int n;
	printf("Enter number of terms\n");
	scanf("%d",&n);
	pthread_create(&thread,0,&child_thread,(void*)n);
	pthread_join(thread,0);
	printf("Child thread completed\n");
	for(int i=0;i<n;i++)
	printf("%d ",fib[i]);
	printf("\n");
}

