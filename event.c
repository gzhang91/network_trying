#include "event.h"

event_t *NewEvent(socket_t *s, int event_type, event_handler_pt ev_ptr) {
	if (!s || s->fd < 0) {
		return NULL;
	}

	event_t *ev = NULL;
	if (event_type <= 0 || event_type >= EVENT_MAX) {
		return ev;
	}

	ev = (event_t *)malloc(sizeof(*ev));
	if (!ev) {
		return NULL;
	}

	ev->s = s;
	ev->event_type = event_type;
	ev->handler = ev_ptr;
	return ev;
}

int AddEventToList(event_list_t *lst, event_t *ev) {

}

int DelEventFromList(event_list_t *lst, event_t *ev) {

}