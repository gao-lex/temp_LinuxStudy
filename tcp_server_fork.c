#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define portnumber 3333

int main(int argc, char *argv[]) 
{ 
	int listen_fd,accept_fd; 
	struct sockaddr_in client_addr; 
	int n;
	int nbytes;
	
	/* 服务器端开始建立sockfd描述符 */ 
	if((listen_fd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:IPV4;SOCK_STREAM:TCP
	{ 
		printf("Socket error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 


	bzero(&client_addr,sizeof(struct sockaddr_in)); // 初始化,置0
	client_addr.sin_family=AF_INET;                 // Internet
	client_addr.sin_addr.s_addr=htonl(INADDR_ANY);  // (将本机器上的long数据转化为网络上的long数据)服务器程序能运行在任何ip的主机上  //INADDR_ANY 表示主机可以是任意IP地址，即服务器程序可以绑定到所有的IP上
	//server_addr.sin_addr.s_addr=inet_addr("192.168.1.1");  //用于绑定到一个固定IP,inet_addr用于把数字加格式的ip转化为整形ip
	n=1;
	
	/* 捆绑sockfd描述符到IP地址 */ 
	//setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int));
        client_addr.sin_port=htons(portnumber);
	if(bind(listen_fd,(struct sockaddr *)(&client_addr),sizeof(client_addr))==-1) 
	{ 
		printf("Bind error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	/* 设置允许连接的最大客户端数 */ 
	listen(listen_fd,5); 
	
	while(1) 
	{ 
		
		accept_fd=accept(listen_fd,NULL,NULL); 
	        if(accept_fd<0)
                {
                      printf("Accept Error:%s\n",strerror(errno)); 
		      continue;
		} 		
		if((n=fork())==0)
		{             
			/* 子进程处理客户端的连接 */ 
		        char buffer[1024];
		        if((nbytes=read(accept_fd,buffer,1024))==-1)
		        {
		        	fprintf(stderr,"Read Error:%s\n",strerror(errno));
		        	exit(1);
		        }
		        buffer[nbytes]='\0';
		        printf("Server received %s\n",buffer);
		        
		        close(listen_fd);
		        close(accept_fd);
		        exit(0);
		}
		else
		        close(accept_fd);
	} 
}
