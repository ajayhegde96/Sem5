#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
	int sd;
	struct sockaddr_in address;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(9704);
	int op1,op2;
	char oper;
	int len=sizeof(address);
	int res=0;
	printf ("Enter two operands and an operator\n");
	scanf("%d %d %c",&op1,&op2,&oper);
	sendto(sd,&op1,sizeof(op1),0,(struct sockaddr *)&address,len);
	sendto(sd,&op2,sizeof(op2),0,(struct sockaddr *)&address,len);
	sendto(sd,&oper,sizeof(oper),0,(struct sockaddr *)&address,len);
	recvfrom(sd,&res,sizeof(res),0,(struct sockaddr *)&address,&len);
	printf("Result from server is\n");
	printf("%d\n",res);
	return 0;
}