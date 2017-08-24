#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int flag=0;
	char t[100];
	char p[20];
	printf("Enter main string\n");
	gets(t);
	printf("Enter pattern\n");
	gets(p);
	int a=strlen(t);
	int b=strlen(p);
	for(int i=0;i<a-b;i++){
		int j=0;
		while(j<b&&t[i+j]==p[j]){
			j++;
		}
		if(j==b){
			flag=1;
			printf("Match Found\n");
			break;
		}
	}
	if(flag==0){
			printf("Match Not Found\n");
		}
}
