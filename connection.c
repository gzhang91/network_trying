#include "connection.h"

connection_t *NewConnection() {
	connection_t *conn = (connection_t *)malloc(sizeof(*conn));
	if (!conn) {
		return NULL;
	}

	return conn;
}