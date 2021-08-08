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
#define MAXDATASIZE 1024
#define MYPORT "2002"



int main(){

int sockfd, numbytes,valread;
char buf[MAXDATASIZE];
struct addrinfo hints, *servinfo, *p;
int rv;
struct sockaddr_in serv_addr;
char buffer[1024]={0};

memset(&hints,0,sizeof(hints));
hints.ai_family = AF_UNSPEC;
hints.ai_socktype= SOCK_STREAM;

if((rv= getaddrinfo(NULL, MYPORT, &hints, &servinfo))!=0)
{
cout<<"error in getaddrinfo"<<endl;}



for(p=servinfo; p!=NULL;p=p->ai_next){

if ((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1)
{
cout<<"client socket error<<"<<endl;
continue;}



if(connect(sockfd, p->ai_addr, p->ai_addrlen) ==-1)
{
close(sockfd);
cout<<"error in connect"<<endl;
continue;

}

break;

}
 
 const char *hello="hello from the client";
send(sockfd, hello, strlen(hello),0);
cout<<"hello messasge sent from client "<<endl;
valread=read(sockfd, buffer, 1024);
cout<<buffer<<endl;




return 0;
}
