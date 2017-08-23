#include <stdio.h>
#include <pthread.h>
void* child_thread(void* param)
{
	int *a=(int*)param;
	int k=3;
	int co=0;
	for(int i=(a[0]+1);i<=a[1];i++)
	{
		int flag=1;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1){
		//printf("%d ",i);
		a[k++]=i;
		co++;
		}
	}
	a[2]=co;
return a;
}
		
				
void main()
{
	pthread_t thread;
	int n,m;
	int arr[100];
	printf("Enter limits\n");
	scanf("%d %d",&n,&m);
	arr[0]=n;
	arr[1]=m;
	pthread_create(&thread,0,&child_thread,(void*)arr);
	int *k;
	pthread_join(thread,&k);
	for(int i=3;i<3+k[2];i++)
	printf("%d ",k[i]);
	printf("\n");
	
}
