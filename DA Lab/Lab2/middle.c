#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int middleschool(int a,int b)
{
	int gcd=1,op=0;
	while(a%2==0 && b%2==0){
		op++;
		gcd=2*gcd;
		a=a/2;
		b=b/2;
	}
	int min=(a>b)?b:a;
	for(int i=3;i<=min;i=i+2)
	{
		op++;
		while(a%i==0 && b%i==0){
			op++;
			gcd=gcd*i;
			a=a/i;
			b=b/i;
		}

		if(a==1||b==1)
			break;
		min=(a>b)?b:a;
	}
	printf("Operation count %d\n",op);
		return gcd;
}
int main()
{
	int m,n;
	printf("Enter two numbers ");
	scanf("%d %d",&m,&n);
	int res=middleschool(m,n);
	printf("GCD of the numbers is %d",res);
	printf("\n");
	return 0;
}