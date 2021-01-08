#include "reactor.h"
#include <stdlib.h>

poller_t g_poller;

// =========================== inner function =============================
int _RegisterPoller(reactor_t *r, int type) {
	char *env = getenv("USE_POLLER"); 
	if (env != NULL) {
		int poll_idx = atoi(env);
		if (poll_idx > 0) {
			
		}

		return 0;
	}

	if (type <= 0 || type > POLL_MAX) {
		type = POLL_SELECT;
	}
	
	switch (type) {
		case POLL_SELECT: {
			
		}
		break;

		case POLL_POLL: {
			
		}
		break;

		case POLL_EPOLL: {

		}
		break;
	}
}

///////////////////////////////////////////////////


// =========================== outter function =============================
reactor_t* NewReactor() {
	reactor_t *r = (reactor *) malloc(sizeof(*r));
	if (!r) {
		return NULL;
	}

	if (!_RegisterPoller(r, 1)) {
		return NULL;
	}

	return r;
}

int AddEvent(reactor_t *r, event_t *ev) {

}

int DelEvent(reactor_t *r, event_t *ev) {

}

int Poll(reactor_t *r) {

}
