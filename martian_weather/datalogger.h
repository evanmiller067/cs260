#ifndef DATALOGGER_H
#define DATALOGGER_H
//datalogger class header

#include "linkedlist.h"


class datalogger
{
	private:
		//linked list data member
		linkedList list;
	
	public:

		//functions
		void addData(int, int, int);
		void removeData(int);
		void printReport(const char*);
		bool containsTimestamp(int);
};

#endif


