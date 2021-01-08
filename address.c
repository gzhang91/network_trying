#include "address.h"

int ParseAddrFromText(address_t *addr_ptr, const char *ip_text, short port) {
	if (!addr_ptr) {
		return -1;
	}

	if (!inet_pton(AF_INET, ip_text, (void *)addr_ptr->addr.sin_addr)) {
		return -1;
	}

	memcpy(addr_ptr->ip_text, ip_text, sizeof(addr_ptr->ip_text));
	addr_ptr->addr_len = sizeof(addr_ptr->addr);
	addr_ptr->port = port;

	return 0;
}

int ParseAddrToText(address_t *addr_ptr, char *ip_text) {
	if (!addr_ptr || !ip_text) {
		return -1;
	}

	if (addr_ptr->addr_len == sizeof(addr_ptr->addr)) {
		memcpy(ip_text, addr_ptr->ip_text, sizeof(addr_ptr->ip_text));
		return 0;
	}

	if (!inet_ntop(AF_INET, (void *)addr_ptr->addr, ip_text, sizeof(struct sockaddr_in))) {
		return -1;
	}

	memcpy(addr_ptr->ip_text, ip_text, sizeof(addr_ptr->ip_text));
	addr_ptr->addr_len = sizeof(addr_ptr->ip_text);
	return 0;
}