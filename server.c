#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<ctype.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
	int sockfd,newfd;
	char buffer[1024];
	struct sockaddr_in server_addr,client_addr;
	socklen_t addr_len = sizeof(client_addr);

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
	listen(sockfd,5);
	printf("TCP server started\n");
	while(1){
		newfd = accept(sockfd,(struct sockaddr*)&client_addr,&addr_len);
		int pid = fork();
		if(pid == 0){
			close(sockfd);
			printf("client connected pid:%d\n",getpid());
			while(1){
				int n = recv(newfd,buffer,sizeof(buffer)-1,0);
				if(n<=0){
					printf("client disconnected  %d\n",getpid());
					break;
				}
				buffer[n] = '\0';
				for(int i=0;i<n;i++){
					buffer[i] = toupper(buffer[i]);
				}
				send(newfd,buffer,n,0);
			}
			close(newfd);
			exit(0);
		}else{
			close(newfd);
		}
	}
	return 0;
}
	
