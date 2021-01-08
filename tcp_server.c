#include "tcp_server.h"

tcp_server_t *NewTcpServer(const char *local_addr, short port) {
	// ´´½¨listenÌ×½Ó×Ö
	socket_t *ls = NewSocket();
	if (!ls) {
		printf("create socket failed\n");
		return NULL;
	}

	SetNonblocking(ls);

	address_t addr;
	memset(&addr, 0x0, sizeof(addr));
	addr

	int ret = 0;

	
	// ret = Bind(ls,);
}