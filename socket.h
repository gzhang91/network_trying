#ifndef _SOCKET_H_
#define _SOCKET_H_

struct socket_s {
	int fd;
	unsigned char invalid;
};

typedef struct socket_s socket_t;

socket_t *NewSocket();
void SetNonblocking(socket_t* s);
int Bind(socket_t *s, struct sockaddr_in *addr, short port);
int Listen(socket_t *s);

#endif // _SOCKET_H_