#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << "sum of all nodes: ";
	int sum = sumOfNodes(root);
	cout << sum;
	
    display(root);
    destroy(root);
    return 0;
}
