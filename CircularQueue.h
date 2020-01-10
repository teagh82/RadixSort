#ifndef _circularQ
#define _circularQ

#include <stdlib.h>

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CircularQueue
{
public:
	int		front;
	int		rear;

	int 	data[MAX_QUEUE_SIZE];
	CircularQueue() { front = rear = 0; }
	~CircularQueue() { }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue( int n ) {
		if( isFull() ) error((char*)"  Error: ť�� ��ȭ�����Դϴ�\n");
		else {
			rear = (rear+1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	int dequeue( ) {
		if( isEmpty() ) error((char*)"  Error: ť�� ��������Դϴ�\n");
		else {
			front = (front+1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	void reset() {front = rear = 0;}
};
#endif