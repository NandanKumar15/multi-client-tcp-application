#include<unistd.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
int main(){
	int sockfd;
	char buffer[1024];
	struct sockaddr_in server_addr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	inet_pton(AF_INET,"127.0.0.1",&server_addr.sin_addr);
	connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
	printf("connected successfully\n");
	while(1){
		printf("enter message\n");
		fgets(buffer,sizeof(buffer),stdin);
		send(sockfd,buffer,strlen(buffer),0);
		int n = recv(sockfd,buffer,sizeof(buffer)-1,0);
		if(n<=0){
			printf("server disconnected\n");
			break;
		}
		buffer[n] = '\0';
		printf("server: %s\n",buffer);
	}
	close(sockfd);
	return 0;
}

