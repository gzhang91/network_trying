#ifndef _BUFFER_H_
#define _BUFFER_H_

static const int BUFSIZE = 4096;

// ÿ��socket��Ӧһ�������������
struct buffer_s
{
	char data[BUFSIZE];
	int begin;
	int end;
} ;

typedef struct buffer_s buffer_t;

// ��content��ӵ�buffer��
int AppendBuffer(buffer_t* buffer, const char *content);

// 
int MoveBuffer(buffer_t* buffer);

// ���buffer
int ClearBuffer(buffer_t* buffer);

#endif // _BUFFER_H_