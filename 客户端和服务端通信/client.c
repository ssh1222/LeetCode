#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SROPT 10001 
#define IP "192.168.43.81"
int main()
{
	struct sockaddr_in server_addr;
	int addr_length = sizeof(server_addr);
	char buf[512] = { 0 };
	//打开socket
	int sock_FD = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_FD < 0)
	{
		perror("socket error");
		return -1;
	}
	//设置服务器的ip和port
	memset(&server_addr, 0, addr_length);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SROPT);
	server_addr.sin_addr.s_addr = inet_addr(IP);
	//发送连接请求
	int ret = connect(sock_FD, (struct sockaddr*)&server_addr, addr_length);
	if(ret < 0)
	{
		perror("connect error");
		close(sock_FD);
		return -1;
	}
	while(1)
	{	
		gets(buf);
		write(sock_FD, buf, sizeof(buf));
		memset(buf, 0, sizeof(buf));
	}
	close(sock_FD);
}
