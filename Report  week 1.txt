ASSIGNMENT(week 01)   REPORT

GROUP - 19


REFERENCE :
1.> Beej’s guide for network programming  (https://beej.us/guide/bgnet/)
2.> youtube (https://youtu.be/JExfKvUgrtI
What's in the code:


1.   Header files included.
1.1. iostream
1.2. stdio.h
1.3. stdlib.h
1.4. string.h
1.5. unistd.h
1.6. sys/types.h
1.7. sys/socket.h
1.8. netinet/in.h
1.9. netdb.h

2.   Functions used in Server side.
2.1. Socket creation. --> sockfd=socket(AF_INET,SOCK_STREAM,0);
2.2. Binding socket to address and port number. --> bind(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr));
2.3. Waiting for client to approach the server. --> listen(sockfd,5);
2.4. Establishing connection between server and client. --> newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&clilen);
2.5. Reading sent message. --> read(newsockfd,buffer,1024);
2.6. Writing message. --> write(newsockfd,buffer,strlen(buffer));

3.   Functions used in Client side.
3.1. Socket creation. --> sockfd=socket(AF_INET,SOCK_STREAM,0);
3.2. Connecting with server. --> connect(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr);
3.3. Reading sent message. --> read(newsockfd,buffer,1024);
3.4. Writing message. --> write(newsockfd,buffer,strlen(buffer));
