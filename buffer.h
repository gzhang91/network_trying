#ifndef _BUFFER_H_
#define _BUFFER_H_

static const int BUFSIZE = 4096;

// 每个socket对应一个输入输出缓冲
struct buffer_s
{
	char data[BUFSIZE];
	int begin;
	int end;
} ;

typedef struct buffer_s buffer_t;

// 将content添加到buffer中
int AppendBuffer(buffer_t* buffer, const char *content);

// 
int MoveBuffer(buffer_t* buffer);

// 清除buffer
int ClearBuffer(buffer_t* buffer);

#endif // _BUFFER_H_