#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
	int sd;
	int op1,op2;
	char oper;
	int res=0;
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(9704);
	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	recvfrom(sd,&op1,sizeof(op1),0,(struct sockaddr *)&cadd,&len);
	recvfrom(sd,&op2,sizeof(op2),0,(struct sockaddr *)&cadd,&len);
	recvfrom(sd,&oper,sizeof(oper),0,(struct sockaddr *)&cadd,&len);
	switch(oper)
	{
		case '+':res=op1+op2;
				 break;
		case '-':res=op1-op2;
				 break;
		case '/':res=op1/op2;
				 break;
		case '*':res=op1*op2;
				 break;
	}
	sendto(sd,&res,sizeof(res),0,(struct sockaddr *)&cadd,len);
	return 0;

}