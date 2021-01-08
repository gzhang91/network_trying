#ifndef _ADDRESS_H_
#define _ADDRESS_H_
/*
	暂时只支持ipv4
*/

struct address_s {
	struct sockaddr_in addr;
	socklen_t addr_len;
	char ip_text[16];
	short port;
};

typedef struct address_s address_t;

int ParseAddrFromText(address_t *addr_ptr, const char *ip_text, short port);

#endif // _ADDRESS_H_