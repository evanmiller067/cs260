#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedlist.h"
#include "family.h"

class hashtable
{
	public:
		hashtable();
		hashtable(const int size);
		~hashtable();
		void insert(const char* key, const family& f);
		family* lookup(const char* key);
		void dumpTable();
	private:
		linkedList** table;
		int tableSize;
		std::size_t hash(const char* key);
};
#endif
