#ifndef QUEUE_H
#define QUEUE_H
#include "resultdata.h"

class queue
{
	public:
		queue(int); //constructor
		~queue(); //destruct
		bool isEmpty(); //test if container is empty
		bool isFull();
		bool enqueue(int, int, int, int);
		resultdata dequeue();
		int peek();
	private:
		int MAX, front, rear, size;
		resultdata queueArray[];
};
#endif
