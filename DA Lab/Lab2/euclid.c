#include <stdio.h>
#include <stdlib.h>
int euclidgcd(int a,int b)
{
	int r,opcount=0;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
		opcount++;
	}
	printf("Operation count is %d",opcount);
	printf("\n");
	return a;
}
int main()
{
	int a,b;
	printf("Enter two numbers ");
	scanf("%d %d",&a,&b);
	int res=euclidgcd(a,b);
	printf("GCD of the numbers is %d",res);
	printf("\n");
	return 0;
}