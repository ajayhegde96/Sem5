#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 9500

int main()
{
	int sd,sdd,portno,clilen,n=1;
	char buf[256];
	struct sockaddr_in serad,cliad;
	int i,value;
	sd=socket(AF_INET,SOCK_STREAM,0);
	serad.sin_family=AF_INET;
	serad.sin_addr.s_addr=INADDR_ANY;
	serad.sin_port=htons(PORTNO);
	bind(sd,(struct sockaddr *)&serad,sizeof(serad));
	listen(sd,1);
	clilen=sizeof(clilen);
	sdd=accept(sd,(struct sockaddr *)&cliad,&clilen);
	n=read(sdd,buf,sizeof(buf));
	struct tm *t;
	time_t tt;
	time(&tt);
	t=localtime(&tt);
	strcpy(buf,asctime(t));
	n=write(sdd,buf,sizeof(buf));
	return 0;
}
