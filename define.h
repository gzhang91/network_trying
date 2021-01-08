#ifndef _DEFINE_H_
#define _DEFINE_H_

// event_type
#define EVENT_READ		1
#define EVENT_WRITE		2
#define EVENT_ERROR		3
#define EVENT_MAX		4

// poll_type
#define POLL_SELECT     1
#define POLL_POLL		2
#define POLL_EPOLL		3
#define POLL_KQUEUE		4
#define POLL_MAX		5

//  π”√poll
#define USE_POLLER		2

#endif // _DEFINE_H_