#include "table.h"

//Please put the impelementation of the required functions here

int sumOfNodes(node *root)
{
	if(root == nullptr)
	{
		return 0;
	}
	if(root->left != nullptr && root->right != nullptr)
	{
		return(root->data + sumOfNodes(root->left) + sumOfNodes(root->right));
	}
}


void copyLeaf(node* src, node* &dest)
{	
	
	if(root != nullptr)
	{
		if(root->left != nullptr)
        }
	//start copy
	node* curr = node;
        while(curr->left != nullptr)
        {
                curr = curr->left;
        }
        sum = curr->data;
}  
