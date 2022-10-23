#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include <sys/socket.h>
#include <sys/types.h>
#include<string.h>
#include <netinet/in.h>


int main() {
	
	
	//time_t equivalent = time(&equivalent);
	time_t t;   // not a primitive datatype
  	time(&t);
  	//equivalent += (15*60);


	char server_message[500] = "Order noted:";
	char serving[256]="Serving time:";
	char buf[200];
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
	
	int i=0;
	while(i!=5)
	{
	client_socket = accept(server_socket, NULL, NULL);
	i++;


	
	// send the message
	recv(client_socket, &buf, sizeof(buf), 0);
	printf("\n %s \n", buf);
	strcat(server_message," ");
	strcat(server_message,ctime(&t));
	char datetime[256]=" ";
	strcat(datetime,ctime(&t));
	strcat(server_message,"\n");
	strcat(server_message,serving);
	strcat(server_message," ");
	strcat(server_message,"Your order will be served after 15 minutes\n");
	send(client_socket, server_message, sizeof(server_message), 0);
	
    	char *department;
	department = strtok(buf, "-");
	while (department != 0) {
	break;
    	}
	
	char *name= strtok(NULL, "-");
	char *rollno= strtok(NULL, "-");
	char *tableno= strtok(NULL, "-");
	char *order= strtok(NULL, "-");
	
	
	///////////////////////CS////////////
	if(strcmp(department,"CS")==0||strcmp(department,"cs")==0)
	{
	FILE *f;
	int count=1;
	char scount[100];
	sprintf(scount,"%d",count);
	f=fopen("CS.txt","a");
	if (f== NULL )
   	{
        printf( "CS.txt file failed to open." ) ;
    	}
    	else
    	{
        if ( strlen ( server_message ) > 0 )
        {  
            fputs("Serial No	Department	Date	Time	Name	Order",f);
            fputs("\n",f);
            fputs(scount, f) ;
            fputs("\t \t CS \t",f);
            fputs(datetime,f);
            fputs(name,f);
            fputs("\t",f);
            fputs(order,f);
            fputs("\n", f) ;
        }
        fclose(f);
    	}
    	}
    	
    	////////////////////////////////SE//////////////
    	else if(strcmp(department,"SE")==0||strcmp(department,"se")==0)
	{
	FILE *f1;
	int count=1;
	char scount[100];
	sprintf(scount,"%d",count);
	f1=fopen("SE.txt","a");
	if (f1== NULL )
   	{
        printf( "CS.txt file failed to open." ) ;
    	}
    	else
    	{
        if ( strlen ( server_message ) > 0 )
        {  
            fputs("Serial No	Department	Date	Time	Name	Order",f1);
            fputs("\n",f1);
            fputs(scount, f1) ;
            fputs("\t \t SE \t \t",f1);
            fputs(datetime,f1);
            fputs(name,f1);
            fputs("\t",f1);
            fputs(order,f1);
            fputs("\n", f1) ;
        }
        fclose(f1);
    	}
    	}
	
	////////////////////////////////////DS/////////////////
	else if(strcmp(department,"DS")==0||strcmp(department,"ds")==0)
	{
	FILE *f2;
	int count=1;
	char scount[100];
	sprintf(scount,"%d",count);
	f2=fopen("DS.txt","a");
	if (f2== NULL )
   	{
        printf( "DS.txt file failed to open." ) ;
    	}
    	else
    	{
        if ( strlen ( server_message ) > 0 )
        {  
            fputs("Serial No	Department	Date	Time	Name	Order",f2);
            fputs("\n",f2);
            fputs(scount, f2) ;
            fputs("\t \t DS \t \t",f2);
            fputs(datetime,f2);
            fputs(name,f2);
            fputs("\t",f2);
            fputs(order,f2);
            fputs("\n", f2) ;
        }
        fclose(f2);
    	}
    	}
	
	
	///////////////////////AI////////////////////////////
	else if(strcmp(department,"AI")==0||strcmp(department,"ai")==0)
	{
	FILE *f3;
	int count=1;
	char scount[100];
	sprintf(scount,"%d",count);
	f3=fopen("AI.txt","a");
	if (f3== NULL )
   	{
        printf( "CS.txt file failed to open." ) ;
    	}
    	else
    	{
        if ( strlen ( server_message ) > 0 )
        {  
            fputs("Serial No	Department	Date	Time	Name	Order",f3);
            fputs("\n",f3);
            fputs(scount, f3) ;
            fputs("\t \t AI \t \t",f3);
            fputs(datetime,f3);
            fputs(name,f3);
            fputs("\t",f3);
            fputs(order,f3);
            fputs("\n", f3) ;
        }
        fclose(f3);
    	}
    	
	
	
	
	}
	if(i==5)
	{
	close(server_socket);
	break;
	}
	}
	
	// close the socket
	
	
	return 0;
}


