#ifndef STACK_H
#define STACK_H


struct point {
	point(): x(0), y(0)
	{
	
	};
	int x;
	int y;
};


class stack
{
	private:
		struct node
		{
			int x;
			int y;
			node *next;
		};
		node *head;
		node *tail;

	public:
		stack();
		~stack();
		bool isEmpty();
		void push(int, int);
		point* pop();
		void peek();
		void print();
};
#endif
