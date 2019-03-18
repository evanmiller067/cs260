#include "planttree.h"
#include <iostream>
using namespace std;

planttree::planttree()
{
	myRoot = nullptr;
}
planttree::~planttree()
{
	delete myRoot;
}
planttree::planttree(const planttree& copy)
{
	myRoot = copyTree(copy.myRoot);
}
planttree& plnattree::operator=(const planttree&)
{
/*
    1.  Deallocate any memory that MyClass is using internally
    2.  Allocate some memory to hold the contents of rhs
    3.  Copy the values from rhs into this instance
    4.  Return *this
*/
void planttree::setRoot(const plant& root)
{
	myRoot = new treenode(root);
}
void planttree::addChildren(const plant& parent, const plnat& left, const plant& right)
{
	trenode* curr = search(myRoot, parent.getID());
	if(curr != nullptr)
	{
		curr->left = new treenode(left);
		curr->right = new treenode(right);
	}
}
void planttree::display()
{
	preOrderPrint(myRoot, 0);
}
void planttree::preOrderPrint(treenode* root, int height)
{
	if(root != nullptr)
	{
		int currHeight = height;
		while(currHeight > 0)
		{
			cout << " ";
			currHeight--;
		}
		cout << root->p << endl;
		preOrderPrint(root->left, ++height);
		preOrderPrint(root->right, height);
	}
}
plant* planttree::findBestGrowth(treenode* root) const
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestGrowth(root->left) == nullptr) ? &(root->p) : findBestGrowth(root->left);
		plant* right = (findBestGrowth(root->right) == nullptr) ? &(root->p) : findBestGrowth(root->right);
		if(root->p.getGrowth() > left->getGrowth() && root->p.getGrowth() > right->getGrowth())
		{
			return &(root->p);
		}
		else
		{
			return (left->getGrowth() >= right->getGrowth()) ? left : right;
		}
	}
}
plant* planttree::findBestWater(treenode* root) const
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestWater(root->left) == nullptr) ? &(root->p) : findBestWater(root->left);
		plant* right = (findBestWater(root->right) == nullptr) ? &(root->p) : findBestWater(root->right);
		if (root->p.getWater() > left->getWater() && root->p.getWater() > right->getWater()) 
		{
			return &(root->p);
		}
		else
		{
			return (left->getWater() >= right->getWater()) ? left : right;
		}
	}
}
plant* planttree::findBestNutrition(treenode* root) const
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestNutrition(root->left) == nullptr) ? &(root->p) : findBestNutrition(root->left);
		plant* right = (findBestNutrition(root->right) == nullptr) ? &(root->p) : findBestNutrition(root->right);
		if(root->p.getNutrition() > left->getNutrition() && root->p.getNutrition() > right->getNutrition())
		{
			return &(root->p);
		}
		else
		{
			return (left->getNutrition() >= right->getNutrition()) ? left : right;
		}
	}
}
