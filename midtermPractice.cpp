#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

struct node
{
    int data;
    node * previous;
    node * next;
};

void build();
void print();
void printBackwards();
void destruct();
int findSmallest(node* head);
void removeLargest(node* head);
int countX(node* head, int x);
void copyOdd(node* source, node** destination);

node * head    = nullptr;
node * tail    = nullptr;
node * newNode = nullptr;
node * current = nullptr;

int main()
{
    build();
    print();
    printBackwards();
    //written functions here//
	cout << "Smallest element: " << findSmallest(head) << endl;
	removeLargest(head);
	print();

    destruct();

    return 0;
}




void build()
{
    srand(time(nullptr));
    for(int index = 0; index < 100; index++)
    {
        newNode = new node;
        newNode->data = rand() % 100 + 1;
        newNode->previous = nullptr;
        newNode->next = nullptr;
        if(!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
}

void print()
{
    int index = 1;
    cout << "\nList printed head to tail:\n\n";
    cout << " ";
    for(current = head; current; current = current->next)
    {
        cout << fixed;
        cout << right;
        cout << setw(3);
        cout << current->data <<  "| "; 
        if(index % 10 == 0 && index != 100)
            cout << endl << " ";
        index++;
    }
    cout << endl << endl;
}

void printBackwards()
{
    int index = 1;
    cout << "Tail to head: \n\n ";
    for(current = tail; current; current = current->previous)
    {
        cout <<"|";
        cout << fixed;
        cout << left;
        cout << setw(3);
        cout << current->data << " "; 

        if(index % 10 == 0 && index != 100) //<--sloppy
            cout << endl << " ";
        index++;
    }
    cout << endl << endl;
}

void destruct()
{
    current = head;
    while(current)
    {
        current = current->next;
        delete head;
        head = current;
    }
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}
int findSmallest(node* head)
{
	//find smallest element in list and return it
	int min = 0;
	if(head->next != NULL)
	{
		int x = head->data;
		int rest = findSmallest(head->next);
		min = (x < rest) ? : rest;
	}
	else
	{
		min = head->data;
	}
	return min;
}
void removeLargest(node* head)
{	
	//find largest
	int max = INT_MIN;
	if(head->next != NULL)
	{
		int x = head->data;
		int rest = removeLargest(head->next);
		max = (x > rest) ? : rest;
	}
	else
	{
		max = head->data;
	}
	//compare largest to node values, then remove matching node
	if(max == head->data)
	{
		
	}
}
