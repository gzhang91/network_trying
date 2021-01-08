#include <stdio.h>
#include "net.h"

int ReadHandler(void *arg) {
	printf("read \n");
}

int WriteHandler(void *arg) {
	printf("write \n");
}

int main(void) {
	reactor_t *r = NewReactor();
	tcp_server_t *svr = NewTcpServer();

	svr
	Poll(r);

	return 0;
}