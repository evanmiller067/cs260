#include <iostream>
#include <cstring>
#include "linkedlist.h"
using namespace std;
linkedList::linkedList(): head(nullptr), size(0)
{}
linkedList::linkedList(const linkedList& copy)
{
	if(copy.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		head = new node;
		head->data = copy.head->data;
		node* newNode = head;
		node* oldNode = copy.head->next;
		while(oldNode != nullptr)
		{
			newNode->next = new node;
			newNode = newNode->next;
			newNode->data = oldNode->data;
			oldNode = oldNode->next;
		}
		newNode->next = nullptr;
	}
}
linkedList::~linkedList()
{
	node* curr = head;
	while(head)
	{
		curr = head->next;
		delete head;
		head = curr;
	}
}
int linkedList::getSize() const
{
	return this->size;
}
bool linkedList::insert(const family& f)
{
	node* newNode = new node;
	newNode->data = f;
	newNode->next = head;
	head = newNode;
	this->size++;
	return true;
}
family* linkedList::search(const char* id)
{
	family* f =nullptr;
	node *curr = head;
	while(curr != nullptr)
	{
		if(strncmp(curr->data.getID(), id, strlen(id)+1) == 0)
		{
			f = &(curr->data);
		}
		curr = curr->next;
	}
	return f;
}
void linkedList::printList()
{
	node* curr = head;
	while(curr != nullptr)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
