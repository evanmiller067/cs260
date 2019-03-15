#include <cstring>
#include <iostream>
#include "hashtable.h"
using namespace std;

hashtable::hashtable(): tableSize(0), table(nullptr)
{}
hashtable::hashtable(const int size): tableSize(size)
{
	table = new linkedList*[tableSize];
	for(size_t i = 0; i < tableSize; i++)
	{
		table[i] = new linkedList();
	}
}
hashtable::~hashtable()
{
	for(size_t i = 0; i < tableSize; i++)
	{
		delete table[i];
	}
	delete [] table;
}
size_t hashtable::hash(const char* key)
{
	size_t result = key[0];
	for(size_t i = 1; i < strlen(key); i++)
	{
		result = result*32 + key[i];
	}
	return (result % tableSize);
}
void hashtable::insert(const char* key, const family& f)
{
	table[hash(key)]->insert(f);
}
family* hashtable::lookup(const char* key)
{
	return table[hash(key)]->search(key);
}
void hashtable::dumpTable()
{
	for(size_t i = 0; i < tableSize; i++)
	{
		cout << "table[" << i << "]:" << endl;
		cout << "List:" << endl;
		table[i]->printList();
		cout << "---------------------" << endl;
	}
}
