#include "stack.h"
#include <iostream>

using namespace std;

stack::stack() 
{
	head = NULL;
	tail = NULL;	
}
stack::~stack()
{
	delete head;
	delete tail;

	 /* node *node;

    	while (node)
    	{
        next = node->next;
        delete node;
        node = next;
     	}*/
}
 
bool stack::isEmpty()
{
	if(head = NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stack::push(int x, int y)
{
	node *newNode = new node;
	newNode->x = x;
	newNode->y = y;
	if(head != NULL)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		head = newNode;
		tail = newNode;
	}
	newNode = NULL;
}
point * stack::pop()
{
  if(head == NULL)
  {
    return NULL;
  }

  point * temp = new point();
  temp->x = head->x;
  temp->y = head->y;

	if(head != NULL)
	{
		node *deletePtr = NULL;
		deletePtr = head;
		head = head->next;
		delete deletePtr;
	}
  

  return temp;
}
void stack::peek()
{
	cout << "X:" << head->x << "  Y:" << head->y << endl;
}

void stack::print()
{
	node *printNode = new node;
	printNode = head;
	while(printNode != NULL)
	{
	  cout << "X:" << printNode->x << "  Y:" << printNode->y << endl;
		printNode = printNode->next;
	}
}
