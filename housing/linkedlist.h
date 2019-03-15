#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "family.h"

class linkedList
{
	private:
		struct node
		{
			family data;
			node* next;
		};
		node* head;
		int size;
	public:
		linkedList();
		linkedList(const linkedList& copy);
		~linkedList();
		int getSize() const;
		bool insert(const family& f);
		family* search(const char* id);
		void printList();
};
#endif
