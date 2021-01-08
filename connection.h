#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "net.h"

struct connection_s {
	socket_t s;
	address_t local;
	address_t peer;

	buffer_t read_buf;
	buffer_t write_buf;
	
	event_t read_ev;
	event_t write_ev;
};

typedef struct connection_s connection_t;

struct connection_list_s {
	connection_t *d;
	struct connection_list_s *next;
};

typedef struct connection_list_s connection_list_t;

connection_t *NewConnection();
int AddConnectionList(connection_list_t *lst, connection_t *conn);
int DelConnectionList(connection_list_t *lst, connection_t *conn);

#endif // _CONNECTION_H_