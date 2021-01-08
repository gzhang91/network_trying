#ifndef _THREAD_QUEUE_H_
#define _THREAD_QUEUE_H_

#include <list>
#include <pthread.h>

/*
	本文件结构提供一个安全访问queue的数据结构
*/

class ThreadQueue
{
public:
	ThreadQueue() {
		pthread_mutex_init(&lock, 
	}

	void Push(ThreadQueue &queue, void *data) {
		pthread_mutex
	}

private:
	pthread_mutex_t lock;
	std::list<void *> data;
};



#endif // _THREAD_QUEUE_H_