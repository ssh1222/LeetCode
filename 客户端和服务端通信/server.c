#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>

#define SPORT 10001

int main()
{
	struct sockaddr_in saddr, caddr;
	char buf[512] = { 0 };
	char buf_send[512] = { 0 };
	socklen_t c_len;
	//创建socket套接字
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	//解决close之后会有一个WAIT_TIME，导致bind失败的问题
	int val = 0;
	if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val,sizeof(int)) < 0)
	{
		perror("setsockport error");
		return -1;
	}
	//绑定ip和port
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(SPORT);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret  = bind(sock_fd, (struct sockaddr*)&saddr, sizeof(saddr));
	if(ret == -1)
	{
		perror("bind error");
		return -1;
	}
	ret = listen(sock_fd, 5);
	if(ret == -1)
	{
		perror("listen error");
		return -1;
	}
	int new_fd = accept(sock_fd, (struct sockaddr*)&caddr,&c_len);
	if(new_fd  == -1)
	{
		perror("accecpt error");
		return -1;
	}
	printf("accept ok mew_fd = %d\n", new_fd);
	while(1)
	{
		ret = read(new_fd, buf, sizeof(buf));
		if(ret == -1)
		{
			perror("read error");
			return -1;
		}
		printf("%s\n", buf);
		gets(buf_send);
		write(new_fd, buf_send, strlen(buf_send));
	}
	close(new_fd);
	close(sock_fd);
	return 0;
}
