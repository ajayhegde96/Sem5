#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int len,result,socket_fd,n=1;
    struct sockaddr_in address;
    char ch[2000],buff[2000];
    socket_fd=socket(AF_INET,SOCK_STREAM,0);
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("127.0.0.1");
    address.sin_port=htons(8000);
    len = sizeof(address);
    result=connect(socket_fd,(struct socketaddr*)&address,len);
    if(result==-1)
    {
        printf("\nERROR\n");
        exit(1);
    }
    while(strcmp(ch,"QUIT")!=0 || (strcmp(buff,"QUIT")!=0))
    {  
        printf("ENTER STRING\n");
        gets(ch);
        ch[strlen(ch)]='\0';
        write(socket_fd,ch,strlen(ch));
        printf("\nREPLY FROM SERVER:");
        n=read(socket_fd,buff,sizeof(buff));
        puts(buff);
        printf("\n");
    }
    return 0;
}
