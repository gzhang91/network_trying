#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

struct tcp_server_s {
	connection_t lst_conn;
	connection_list_t *lst;
};

typedef struct tcp_server_s tcp_server_t;

tcp_server_t *NewTcpServer();

#endif // _TCP_SERVER_H_