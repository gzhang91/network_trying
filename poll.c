#include <iostream>
#include <vector>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>

/*
	使用poll实现reactor模式
	1. 接收数据，调用read
	2. 发送数据，发送不完整，先放入缓冲区中，关注POLLOUT事件，继续发送
    
	int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
	int listen(int sockfd, int backlog);
*/


static const short PORT = 8090;

int main() {
	
	

	PollFdArray poll_fds;
	PollFd poll_fd = {0, 0, 0};
	poll_fd.fd = ls_fd;
	poll_fd.events = POLLIN;
	poll_fds.push_back(poll_fd);

	bool quit = false;
	int ready_fds = 0;
	struct sockaddr_in clt_addr;
	socklen_t addr_len = 0;
	char buff[BUFSIZE] = {0};

	while (!quit)
	{
		ready_fds = poll(poll_fds.data(), poll_fds.size(), -1);
		if (ready_fds < 0) // err
		{
			printf("poll failed, errno: %d\n", errno);
			break;
		}

		if (ready_fds == 0) // timeout
		{
			printf("timeout \n");
			continue;
		}

		printf("ready_fds [%d]\n", ready_fds);
	
		PollFdArray::iterator it = poll_fds.begin();
		for (; ready_fds > 0 && it != poll_fds.end(); it++)
		{
			printf("hand [%d]\n", it->fd);
			if (it->revents & POLLIN) {// 输入 
				if (it->fd == ls_fd) // listen socket
				{	
					printf("listen\n");
					ready_fds--;
		
					/* int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); */
					memset(&clt_addr, 0x0, sizeof(clt_addr));
					addr_len = sizeof(clt_addr);

					int conn_fd = accept(ls_fd, (struct sockaddr *)&clt_addr, &addr_len);
					if (conn_fd < 0)
					{
						printf("accept faild, errno: %d\n", errno);
						continue;
					}
					// setnonblocking(conn_fd);

					poll_fd.fd = conn_fd;
					poll_fd.events = POLLIN;
					poll_fd.revents = 0;
					poll_fds.push_back(poll_fd); 
					/*
						const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
					*/
					char ip[16] = {0};
					inet_ntop(AF_INET, (void *)&clt_addr.sin_addr, ip, sizeof(ip)); 
					printf("accept a new connection, fd: %d, ip: %s, port: %d\n", conn_fd, ip, ntohs(clt_addr.sin_port));

					continue;
				} else {
					printf("read \n");
					ready_fds --;

					int nreads = read(it->fd, buff, BUFSIZE);
					if (nreads < 0) // read failed
					{
						printf("read failed, errno: %d", errno);
						poll_fds.erase(it);
						it --;
						continue;
					}

					if (nreads == 0) // close
					{
						printf("connection closed, fd: %d\n", it->fd);
						close(it->fd);
						poll_fds.erase(it);
						it --;
						continue;
					}

					buff[nreads] = 0;
					printf("read[%d]: %s\n", it->fd, buff);

					write(it->fd, buff, strlen(buff));
				}
			}
			
		
			/*if (it->revents & POLLOUT)
			{
				int nwrites = write(it->fd, buff, sizeof(buff));
			}*/
		}
	}

	return 0;
}

