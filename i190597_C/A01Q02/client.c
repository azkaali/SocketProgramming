// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 16384

// Driver code
int main() {


	int sockfd;
	char buffer[MAXLINE];
	char hello[MAXLINE];
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n, len;
	printf("Enter the movie's name:\n1. 2012\n2. Avatar\n3. Clash of the Titans\n4. Les Miserables\n5. The Godfather\n6. A Beautiful Mind\n7. Amadeus\n8. Star wars\n9. The Expendables I\n");
	gets(hello);
	
	printf("What do you wish to see? \n");
	printf("1. Polarity \n2. Rating\n3. Sentiments \n Enter 0 if you wish to stop taking file names\n");
	char input[100];
	while(strcmp(input,"0")!=0)
	{
	gets(input);
		
	strcat(hello,",");
	strcat(hello,input);
	if(strcmp(input,"0")==0)
	{
	break;
	}	
	}
	
	
	
	sendto(sockfd, (const char *)hello, strlen(hello),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	printf("Movie name entered.\n");
		
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				0, (struct sockaddr *) &servaddr,
				&len);
	buffer[n] = '\0';
	printf("%s\n", buffer);

	close(sockfd);
	return 0;
}
