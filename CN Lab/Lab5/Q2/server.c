#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define PORTNO 9734

int main()
{
	int sd,csd,portno,clilen,n=1,result;
	fd_set readfds,testfds;
	struct sockaddr_in serad,cliad;
	int i,value;
	sd=socket(AF_INET,SOCK_STREAM,0);
	serad.sin_family=AF_INET;
	serad.sin_addr.s_addr=INADDR_ANY;
	serad.sin_port=htons(PORTNO);
	bind(sd,(struct sockaddr *)&serad,sizeof(serad));
	listen(sd,5);
	FD_ZERO(&readfds);
	FD_SET(sd,&readfds);
	while(1){
	char buf[256];
	int fd;
	int nread;
	testfds=readfds;
	printf("server waiting\n");
	result=select(FD_SETSIZE,&testfds,(fd_set*)0,(fd_set*)0,(struct timeval*)0);
	if(result<1){
			perror("server5");
			exit(1);
		}
	for(fd=0;fd<FD_SETSIZE;fd++){
		if(FD_ISSET(fd,&testfds)){
	if(fd==sd){
	clilen=sizeof(cliad);
	csd=accept(sd,(struct sockaddr *)&cliad,&clilen);
	FD_SET(csd,&readfds);
	printf("adding client on fd %d\n",csd);}
	else
					{	
					ioctl(fd,FIONREAD,&nread);
					if(nread==0){
						close(fd);
						FD_CLR(fd,&readfds);
						printf("removing client on fd %d\n",fd);
					}
					else{
						read(fd,buf,sizeof(buf));
						sleep(5);
						for(int i=0;i<strlen(buf);i++){
							if(buf[i]>='a'&&buf[i]<='z')
								buf[i]-=32;
						}
						n=write(fd,buf,sizeof(buf));
					}
				}
	
	}
}
}
	return 0;
}
