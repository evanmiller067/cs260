#ifndef ROVER_H
#define ROVER_H
#include "stack.h"
#include "queue.h"



//rover class header
class rover
{
	private:
		int ID;
		point curr_loc;
		stack visited_loc;
		queue *scans; //pointer to results queue
	public:
		
		//constructor
		rover();
		rover(int ID, const int &MAX_RESULTS, queue &sharedQueue);
		
		//functions
		void deploy();
		void move(int x, int y); //move rover to x,y and store locations in stack
		void corescan();// performs a core scan and returns results to the queue
		void dock(); // returns rover to base
		
};
#endif
