#include <stdio.h>
#include <pthread.h>
void* child_thread(void* param)
{
	int *a=(int*)param;
	int sum=0;
	for(int i=1;i<=a[0];i++)
	{
		if(a[i]>0)
		sum+=a[i];
	}
return (void*)sum;
}
void main()
{
	pthread_t thread;
	int n;
	int arr[n+1];
	int sum;
	printf("Enter number of terms\n");
	scanf("%d",&n);
	arr[0]=n;
	printf("Enter numbers\n");
	for(int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	pthread_create(&thread,0,&child_thread,(void*)arr);
	pthread_join(thread,&sum);
	printf("Child thread completed\n");
	printf("Sum of non-negative terms is %d\n",sum);
}
	
