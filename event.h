#ifndef _EVENT_H_
#define _EVENT_H_

#include "inet.h"

typedef int (*event_handler_pt)(void *arg);

struct event_s {
	socket_t *s;
	int event_type;
	event_handler_t handler;
};

typedef struct event_s event_t;

struct event_list_s {
	event_t ev;
	struct event_list_s *next;
};

typedef struct event_list_s event_list_t;

event_t *NewEvent(socket_t *s, int event_type, event_handler_pt ev_ptr);
int AddEventToList(event_list_t *lst, event_t *ev);
int DelEventFromList(event_list_t *lst, event_t *ev);

#endif // _EVENT_H_