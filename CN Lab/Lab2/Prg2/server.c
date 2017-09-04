#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8000
int main(int argc, char const *argv[])
{
    int sock_fd,new_sock_fd,portno,cli_len,n=1;
    char buff[2000];
    char msg[2000];
    struct sockaddr_in server_add,client_add;
    int i,val;
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    server_add.sin_family=AF_INET;
    server_add.sin_addr.s_addr=INADDR_ANY;
    server_add.sin_port=htons(PORT);
    bind(sock_fd,(struct sockaddr *)&server_add,sizeof(server_add));
    listen(sock_fd,1);
    cli_len=sizeof(cli_len);
    new_sock_fd=accept(sock_fd,(struct sockaddr*)&client_add,&cli_len);
    do
    {
        n=read(new_sock_fd,buff,sizeof(buff));
        if(strcmp(buff,"QUIT")==0)
            break;
        printf("\nMessage:%s\n",buff);
        gets(msg);
        msg[strlen(msg)]='\0';
        strcpy(buff,msg);
        n=write(new_sock_fd,buff,sizeof(buff));
    }while(strcmp(buff,"QUIT")!=0 || (strcmp(msg,"QUIT")!=0));
    return 0;
}
