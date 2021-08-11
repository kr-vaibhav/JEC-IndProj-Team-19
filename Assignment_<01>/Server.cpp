#include<iostream>
using namespace std;
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <netdb.h>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<signal.h>
#include<string>
#define BUF_SIZE 500
#define MYPORT "2002"
#define BACKLOG 5


int main(void){


int sockfd, new_fd, valread,  r;
struct addrinfo hints, *servinfo, *p;
struct sockaddr_storage their_addr;
socklen_t sin_size;
int yes=1;
char s[INET_ADDRSTRLEN];
char buffer[1024]={0}; 

memset(&hints, 0, sizeof(hints));
hints.ai_family= AF_UNSPEC;
hints.ai_socktype= SOCK_STREAM;
hints.ai_flags= AI_PASSIVE;

if((r= getaddrinfo(NULL, MYPORT, &hints, &servinfo))!=0)
{
cout<<"error in getaddrinfo"<<endl;}



for(p=servinfo; p!=NULL;p=p->ai_next){

if ((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1)
{
cout<<"server socket error<<"<<endl;
continue;}

if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))==-1)
{
cout<<"setsockopt error "<<endl;
exit(1);}

if(bind(sockfd, p->ai_addr, p->ai_addrlen)==-1)
{
cout<<"bind error"<<endl;
continue;}

break;

}

freeaddrinfo(servinfo);

if(p==NULL)
{
cout<<"error in binding"<<endl;
exit(1);}


if(listen(sockfd,BACKLOG)==-1)
{
cout<<"error in listening"<<endl;
exit(1);}

int i=1;
while(i<5){

    sin_size = sizeof(their_addr);
    new_fd= accept(sockfd, (struct sockaddr*)&their_addr, &sin_size);
    if(new_fd ==-1)
    {
      cout<<"error in accept"<<endl;
        continue;}

    
    valread=read(new_fd,buffer,1024);
    cout<<buffer<<" "<<i<<endl;
    
    const char *hello="Hello from server to client ";
    send(new_fd, hello, strlen(hello),0);
    cout<<"hello message sent via server to client  "<<i<<endl<<endl<<endl;
    if (i==4){
    cout<<"this was last connection"<<endl;
    i++;}
    else
    i++;
    
   
}



return 0;
}
