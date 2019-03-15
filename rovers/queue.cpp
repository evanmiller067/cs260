#include "queue.h"
#include "resultdata.h"

using namespace std;

//constructor
queue::queue(int argMAX)
{
	//queueArray = new resultdata[argMAX];
	front = -1;
	rear = -1;
	size = 0;
	MAX = argMAX;
}
queue::~queue()
{
	//delete [] queueArray;
}
bool queue::isEmpty()
{
	return(front == -1 && rear == -1);
}
bool queue::isFull()
{
	return((rear+1)%MAX == front);
}
bool queue::enqueue(int ID, int x, int y, int corescan)
{
	bool enq = false;
	if(!this->isFull())
	{
		queueArray[front].add(ID, x, y, corescan);
		front++, size++;
		front %= MAX;
		enq = true;
	}
	return enq;
	/* if(isFull())
	{
		return;
	}
	if(isEmpty())
	{
		front = rear = 0;
	}
	else
	{
		rear = ((rear+1)%MAX);
	}
	queueArray.add(ID, x, y, corescan) */;
}
resultdata queue::dequeue()
{
	resultdata constRear = queueArray[rear];
	if(!this->isEmpty())
	{
		rear++, size++;
		rear %= MAX;
	}
	return constRear;
}
/*
int queue::peek()
{
	if(front == -1)
	{
		return -1;
	}
	else 
	{
		return queueArray[front];
	}
}*/

