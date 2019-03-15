#ifndef FAMILYMGR_H
#define FAMILYMGR_H
#include <iostream>
#include "family.h"
#include "hashtable.h"
class familymgr
{
	private:
		hashtable table;
	public:
		familymgr();
		void addFamily(const family& f);
		void printAllFamilies();
		void printSmallCircle(const char* id);
};
#endif
