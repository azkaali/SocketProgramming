// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT	 8080
#define MAXLINE 16384

// Driver code
int main() {
	char reader;
	char filename1[100]="";
	char filename2[100]="";
	char filename3[100]="";
	char all[16384]="";
	char polarity[2048]="";
	char *p=NULL;
	char rating[2048]="";
	char sentiments[4028]="";
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(cliaddr); //len is value/resuslt

	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				0, ( struct sockaddr *) &cliaddr,
				&len);
	buffer[n] = '\0';
	printf("%s",buffer);
	char moviename[256];
	strcpy(moviename,strtok(buffer, ","));
	strcat(filename1,moviename);
	strcat(filename2,moviename);
	strcat(filename3,moviename);
	
	char *token1= strtok(NULL, ",");
	char *token2= strtok(NULL, ",");
	char *token3= strtok(NULL, ",");
	
	printf("User has entered : %s\n", moviename);
		
	printf("\nToken1 : %s\n", token1);
	printf("\nToken2 : %s\n", token2);
	printf("\nToken3 : %s\n", token3);

	if(strcmp(token1,"polarity")==0||(strcmp(token2,"polarity")==0)||(strcmp(token3,"polarity")==0))
	{
	printf("THIS IS POLARITY\n") ;
	strcat(filename1,"/polarity.txt");
	
	if (0)
	    {
	//	printf( "Polarity.txt file failed to open." ) ;
	    }
	    else
	    {
		printf("The file is now opened.\n") ;
		FILE *f=fopen(filename1,"r");
		 while( fgets ( polarity, 2048, f))
		{
		    printf( "%s\n" , polarity) ;
		}
		strcat(all,polarity);
	    }	  
	  }
	 if(strcmp(token1,"rating")==0||(strcmp(token2,"rating")==0)||(strcmp(token3,"rating")==0))
	 {

	printf("THIS IS RATING\n") ;
	strcat(filename2,"/rating.txt");
	
	if (0)
	    {
	//	printf( "Rating.txt file failed to open." ) ;
	    }
	    else
	    {
		printf("The file content:\n") ;
		FILE *f=fopen(filename2,"r");
		while( fgets ( rating, 2049, f)  )
		{
		    printf( "%s\n" , rating) ;
		}
		strcat(all,rating);
	    }
	}
	 if((strcmp(token1,"sentiments")==0)||(strcmp(token2,"sentiments")==0)||(strcmp(token3,"sentiments")==0))
	{ 
	printf("THIS IS SENTIMENTS\n") ;
	strcat(filename3,"/sentiments.txt");
	int c;
	FILE *f=fopen(filename3,"r");
	if ( 0)
	    {
		printf( "Sentiments.txt file failed to open." ) ;
	    }
	    else
	    {	 
		printf("The file content: \n") ;
	  
		while ((reader = fgetc(f)) != EOF){
		 printf( "%c" , reader) ;
		 sentiments[c]=reader;
		c++;
		}
		fclose(f) ;
		strcat(all,sentiments);
		printf("\nThe file is now closed.") ;
	    }
	 }
	else
	 {
	 
		printf("file not found\n");

	 }
	
	sendto(sockfd, (const char *)all, strlen(all),
		0, (const struct sockaddr *) &cliaddr,
			len);
	
	return 0;
}
