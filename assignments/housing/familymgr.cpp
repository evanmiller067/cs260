#include "familymgr.h"
#include <iostream>
using namespace std;

familymgr::familymgr(): table(7877) 
{}
void familymgr::addFamily(const family& f)
{
	table.insert(f.getID(), f);
}
void familymgr::printAllFamilies()
{
	table.dumpTable();
}
void familymgr::printSmallCircle(const char* id)
{
	cout << "Printing family and imediate friends " << id << endl;
	cout << "== Family ==" << endl;
	family* f = table.lookup(id);
	cout << *f << endl;
	cout << "== Friends (1 level) ==" << endl;
	char** friendsList = f->getFriends();
	for(int i = 0; i < f->getNumberOfFriends(); i++)
	{
		family* fr = table.lookup(friendsList[i]);
		cout << *fr << endl; 
	} 
}
