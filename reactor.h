#ifndef _REACTOR_H_
#define _REACTOR_H_

#include "net.h"

struct poller_s {
	void *handler;

	void *(*new)();
	int (*add)(void *p, int fd, short events);
	int (*del)(void *p, int fd, short events);
	int (*dispatch)(void *p);
};

extern poller_t g_poller;

typedef struct poller_s poller_t;

struct reactor_s {
	__thread only_tid;
	poller_t poller;
	
	event_list_t ev_lst;
};

typedef struct reactor_s reactor_t;

// Inner function
int _RegisterPoller(reactor_t *r, int type);

// Outter function
reactor_t* NewReactor();
int AddEvent(reactor_t *r, event_t *ev);
int DelEvent(reactor_t *r, event_t *ev);
int Poll(reactor_t *r);

#endif //_REACTOR_H_