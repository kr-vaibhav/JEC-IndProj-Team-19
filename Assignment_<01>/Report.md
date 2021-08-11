ASSIGNMENT(week 01) REPORT

GROUP - 19
 
 
 Socket programming- It is a way of connecting two nodes on a network to communicate.

 What is socket?
 - A way to to speak to other programs using standard UNIX file descriptors.
 
 File descriptor - It's a no. that uniquely identifies an open file in computer's operating system.
 		    contains the resource, and how to acess it.

 In UNIX any I/O is done by reading/writing to a file descriptor.
 
 How to get file descriptor?
 - call socket(), it returns socket descriptor, communicate through it by using { send(), recv() } socket calls.
 - more details about them in man pages.
 
 TCP/IP works in 5 layer model.
 1.> APPLICATION LAYER   - Tcp-(FTP, SMTP), Udp(DNS, TELNET).
 2.> TRANSPORT LAYER     - TCP(SOCK_STREAM/ Transmission control protocol) and 
 			    UDP(SOCK_DGRAM/ Userdata datagram protocol), mainly these two.
 3.> INTERNET LAYER      - IP( IPv4 or IPv6).
 4.> NETWORK LAYER       - Ethernet, Wi-fi, Bluetooth, Lte, 3G etc.
 5.> PHYSICAL LAYER      - Copper, Fiber optics, Wireless transmitters.		    
 
 Transport layer->       1. SOCK_STREAM - connection oriented, error free output and in order, slower than SOCK_DGRAM.
 		          2. SOCK_DGRAM -  connection-less, faster than Tcp.
			
			   Port Number -  beside an IP address there is another address that is used by TCP & UDP.



TRANSPORT LAYER:


 DIFFERENT STRUCTS USED IN SOCKET PROGG.
    - various data types used by the socket interface
 


1st.>     struct addrinfo{		  // this is used to prepare the socket address structures
					     for subsequent use. also used in host name lookups,
					     service name lookups, etc.
					     
	   int			ai_flags;	 // AI_PASSIVE, etc.
	   int			ai_family;	 // AF_INET, AF_UNSPEC(uses whatever AF_INET or 
	   					    AF_INET6 accordingly to use)
	   int			ai_socktype;	 // SOCK_STREAM, _DGRAM.
	   int 		ai_protocol;	 // use 0 for 'any'
	   size_t		ai_addrlen;	 // size of ai_addr in bytes
	   struct sockaddr     *ai_addr;	 // struct sockaddr_in or _in6
	   char		*ai_canonname	 // full canonical hostname
	   
	   struct  addrinfo	*ai_next;	 // linked list, next node
	   };


	  load this struct and then call getaddrinfo(), it returns a pointer to a new linked list
	  (*ai_next) of these structures filled with things needed.

	  ai_addr in the strucr addrinfo is a pointer to struct sockaddr.




2nd.>	   struct sockaddr{			// it holds socket address info for many types of 
						   sockets.
	   
	   unsigned short 	sa_family;	// address family, AF_INET, ..._6INET
	   char		sa_data[14];	// 14 bytes of protocol address,
	   					    contains destination address and port no. of
	   					    the socket.
	   	   	
	   };



3rd.>	   struct sockaddr_in{			// a parallel struct (in for internet) to be
						   used with IPv4.
	   
	   short int 			sin_family;	// address family
	   unsigned short int		sin_port;	// port number
	   struct in_addr		sin_addr;	// internet address
	   unsigned char		sin_zero[8]	// same size as struct sockaddr
	   
	   };
 
 sin_zero included to pad the structure to the lenght of struct sockaddr,
 should be set to all zero with the function memset().

 sin_addr is a struct in_addr.
 
 
 
 
4th.>	   struct in_addr {
	   
	   unit32_t 	s_addr;      // 32-bit( 4 bytes IP address in NETWORK BYTE ORDER )
	   };

  example, struct sockaddr_in ina;
  	    ina.sin_addr.s_addr;	// it refernces 4bytes network byte order







INTERNET LAYER:     - IPv4( 4 bytes), IPv6( 16 bytes).
 
 consider ip address as street address and port number as room number.
 
 Byte Order - BIG ENDIAN-      big end of number stored first.
 	       LITTLE ENDIAN-	small end of number stored first.
 	       
 	       BIG ENDIAM = NETWORK BYTE ORDER.
 	       
 	       different computers store hexadecimal numbers in different order that
 	       is there  HOST BYTE ORDER.
 	       
 	       to allow machines of different byte order to communicate, it must be converted 
 	       to network byte order before sending and back to host byte order while receiving.
 	       
 	       htons() - Host to network short
 	       htonl() - Host to network long
 	       ntohl() - Network to host long
 	       ntohs() - Network to host short
 	       more can be found about them in man pages.






	       - functions that allow to manipulate IP address :
 		      
                 1st to store IP address = struct sockaddr_in sa;
 	         function to use inet_pton = converts an ip address to numbers and dot 
 	         notations.
      	         inet_pton (Presentable to network)
 	         conversion as follows :  inet_pton(AF_INET,"10.12.110.57", &(sa.sin_addr));
 		      
                to revert the conversion : inet_ntop(network to presentable
 	        as follows :
 	        
 	        
 	        
                char ip4[INET_ADDRSTRLEN];
 	        struct sockaddr_in sa;
    	        inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN];
 	        cout<<"the IPv4 address is "<<ip4<<endl;






.     Header files included.
.     iostream
.     stdio.h
.     stdlib.h
.     string.h
.     unistd.h
.     sys/types.h
.     sys/socket.h
.     netinet/in.h
.     netdb.h

.     Functions used in Server side.
.     Socket creation. --> sockfd=socket(AF_INET,SOCK_STREAM,0);
.     Binding socket to address and port number. --> bind(sockfd,(struct sockaddr*) 		     &serv_addr,sizeof(serv_addr));
.     Waiting for client to approach the server. --> listen(sockfd,5);
.     Establishing connection between server and client. --> newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&clilen);
.     Reading sent message. --> read(newsockfd,buffer,1024);
.     Writing message. --> write(newsockfd,buffer,strlen(buffer));

.     Functions used in Client side.
.     Socket creation. --> sockfd=socket(AF_INET,SOCK_STREAM,0);
.     Connecting with server. --> connect(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr);
.     Reading sent message. --> read(newsockfd,buffer,1024);
.     Writing message. --> write(newsockfd,buffer,strlen(buffer));






SOURCE OF LEARNING - Beej's guide to Network Programming
		      Link -(https://beej.us/guide/bgnet/)
		      
		      Youtube -(https://youtu.be/JExfKvUgrtI)




 	        		   
