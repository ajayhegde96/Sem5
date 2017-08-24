#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,temp,oc=0;
	printf("Enter number of terms\n");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		a[i]=n-i;

	printf("Before sorting\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++){
			oc++;
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After Sorting\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nOperation Count is %d\n",oc);
}