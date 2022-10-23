#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>


#include <netinet/in.h>
int main() {
	
	//char request[256] = "Hello I am Client are you there";
	char buf[200];
	char dept[1000];
	char name[100];
	char rollno[100];
	char order[100];
	char table[100];
	
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));

	printf("Enter your department: \n");
	gets(dept);
	//puts(str);
	printf("Enter your name: \n");
	gets(name);
	printf("Enter your roll no.: \n");
	gets(rollno);
	printf("Enter your order: \n");
	gets(order);
	printf("Enter your table no.: \n");
	gets(table);
	

	//printf("Order details: \n %s \n %s \n %s \n  %s \n %s \n",	name,rollno,dept,order,table);
	//snprintf(whole,"%s: %s: %s",dept , name, rollno);
	
	strcat(dept,"-");
	strcat(dept,name);
	strcat(dept,"-");
	strcat(dept,rollno);
	strcat(dept,"-");
	strcat(dept,table);
	strcat(dept,"-");
	
	printf("Order by: \n %s \n",dept);
	
	printf("Order item: \n %s \n",order );
	
	strcat(dept,order);
	
	send(sock, dept, sizeof(dept), 0);
	recv(sock, &buf, sizeof(buf), 0);
	printf("\n %s \n", buf);
	
	close(sock);

	return 0;
}

