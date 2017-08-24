#include <stdio.h>
#include <stdlib.h>
int consecutive(int m,int n)
{	
	int t,rem,gcd=1,op=0;
	t=(m>n)?n:m;
	while(t>0){
		op++;
	rem=m%t;
	if(rem==0){
		rem=n%t;
		if(rem==0){
			gcd=t;
			printf("Operation count %d\n",op);
			return gcd;
		}
	}
		if(rem!=0){
		t--;
		}
	}
}
int main()
{
	int m,n;
	printf("Enter two numbers ");
	scanf("%d %d",&m,&n);
	int res=consecutive(m,n);
	printf("GCD of the numbers is %d",res);
	printf("\n");
	return 0;
}