#include "scandata.h"
#include "rover.h"
#include <iostream>

using namespace std;

rover::rover()
{

}
rover::rover(int ID, const int &MAX_RESULTS, queue &sharedQueue)
{
	this->ID = ID;
	scans = &sharedQueue;
}

void rover::deploy()
{
	//deploy rover
	cout << "Rover (ID " << ID << ")";
	cout << " deploying..." << endl;
	cout << "Rover (ID " << ID << ")";
	cout << " ready." << endl;
	visited_loc.push(curr_loc.x, curr_loc.y);
}
void rover::move(int x, int y)
{
	//move rover to new x, y and store location in linked list class
	cout << "Rover (ID " << ID << ") moving to location ";
	cout << x << ", " << y << "." << endl;
	point* new_loc = new point();
	new_loc->x =x;
	new_loc->y =y;
	visited_loc.push(new_loc->x, new_loc->y);
	curr_loc.x = x;
	curr_loc.y = y;
	delete new_loc;
}
void rover::corescan()
{
	//scan data at location and return results to queue
	cout << "Rover (ID " << ID << ") scanning." << endl;
	//call scandata with current location,store results in shared queue
	int data = scandata::getScandata(curr_loc.x, curr_loc.y);
  // Submit data and location into the queue
	scans->enqueue(ID, curr_loc.x, curr_loc.y, data);
}
void rover::dock()
{
	//return rover to base(0,0),output all moves to base.
	cout << "Rover (ID " << ID << ") returning to base." << endl;
	point * prev_loc;

	while(!visited_loc.isEmpty())
	{
		prev_loc = visited_loc.pop();
		cout << "Rover (ID " << ID << ") moving to location ";
		cout << prev_loc->x << ", " << prev_loc->y << endl;
		curr_loc.x = prev_loc->x;
		curr_loc.y = prev_loc->y;
	}

	//print out all backtracking moves back to base then
	cout << "Rover (ID " << ID << ") at base and docked.";
  // pop creates a new struct so we need to delete it
  delete prev_loc;
}
