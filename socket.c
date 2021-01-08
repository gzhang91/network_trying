#include "socket.h"

socket_t * NewSocket() {
	socket_t *s = (socket_t *)malloc(sizeof(*s));
	if (!s) {
		return NULL;
	}

	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		free(s);
		return NULL;
	}

	s->fd = fd;
	s->invalid = 0;

	return s;
}

// int fcntl(int fd, int cmd, ... /*arg*/);
void SetNonblocking(int fd) {
	// getfd
	int get_flag = fcntl(fd, F_GETFL, NULL);
	if (get_flag < 0)
	{
		printf("fcntl failed, errno: %d\n", errno);
		return;
	}
	
	get_flag != O_NONBLOCK;

	int ret = fcntl(fd, F_SETFL, get_flag);
	if (ret < 0)
	{
		printf("fcntl faild, errno: %d\n", errno);
		return;
	}
}

int Bind(socket_t *s, struct sockaddr_in *addr, short port) {
	if (s && s->fd != -1) {
		return -1;
	}

	struct sockaddr_in sa;
	memset(&sa, 0x0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = htonl(addr->sin_addr.s_addr);
	int ret = bind(s->fd, (struct sockaddr *)&sa, sizeof(sa));
	if (ret < 0) {
		return -1;
	}

	return 0;
}

int Listen(socket_t *s) {
	if (s && s->fd != -1) {
		return -1;
	}

	int ret = listen(s->fd, 256);
	if (ret < 0) {
		return -1;
	}

	return 0;
}