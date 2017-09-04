#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int len,result,sd,n=1;
	struct sockaddr_in address;
	char ch[256],buf[256];
	sd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(9734);
	len=sizeof(address);
	result=connect(sd,(struct sockaddr *)&address,len);
	if(result==-1){
		perror("Client Error");
		exit(1);
	}
	printf("\nconvert to upper ");
	gets(ch);
	ch[strlen(ch)]='\0';
	write(sd,ch,strlen(ch));
	n=read(sd,buf,sizeof(buf));
	puts(buf);
	return 0;

}
