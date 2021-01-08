#ifndef _POLL_H_
#define _POLL_H_

/*

int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	struct pollfd {
	   int   fd;         
	   short events;     
	   short revents;   
	};
*/

typedef struct pollfd poll_fd_t;

struct poll_s
{
	poll_fd_t *elt;
	int nelts;
	int nalloc;
};

tyepdef struct poll_s poll_t;

int New(poll_t *p);
int Add(poll_t *p, int fd, short events);
int Del(poll_t *p, int fd, short events);
int Poll(poll_t *p);

#endif // _POLL_H_