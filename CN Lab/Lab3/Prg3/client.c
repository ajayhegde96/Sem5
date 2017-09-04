//prg2 client
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int len,result,sockfd,n=0,m=0;
struct sockaddr_in address;

sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(10600);
len = sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1){
perror("\nCLIENT ERROR");
exit(1);
}


char line[100];
printf("Enter line: ");
gets(line);
send(sockfd,line,100,0);
char word[100];
printf("Word : ");
gets(word);
send(sockfd,word,100,0);
char replace[100];
printf("Replacing Word : ");
gets(replace);
send(sockfd,replace,100,0);
char newline[100];
recv(sockfd,newline,100,0);
printf("New Line : %s\n",newline);
int pid;
recv(sockfd,&pid,sizeof(int),0);
printf("Pid is %d\n", pid);
return 0;
}