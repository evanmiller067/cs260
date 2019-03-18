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
planttree& planttree::operator=(const planttree& root)
{
/*
    1.  Deallocate any memory that MyClass is using internally
    2.  Allocate some memory to hold the contents of rhs
    3.  Copy the values from rhs into this instance
    4.  Return *this
*/
}
void planttree::setRoot(const plant& root)
{
	myRoot = new treenode(root);
}
void planttree::addChildren(const plant& parent, const plant& left, const plant& right)
{
	treenode* curr = search(myRoot, parent.getID());
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
plant* planttree::findBestGrowth() const
{
	return findBestG(myRoot);
}
plant* planttree::findBestG(treenode* root) const
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestG(root->left) == nullptr) ? &(root->p) : findBestG(root->left);
		plant* right = (findBestG(root->right) == nullptr) ? &(root->p) : findBestG(root->right);
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
plant* planttree::findBestWater() const
{
	return findBestW(myRoot);
}
plant* planttree::findBestW(treenode* root) const
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestW(root->left) == nullptr) ? &(root->p) : findBestW(root->left);
		plant* right = (findBestW(root->right) == nullptr) ? &(root->p) : findBestW(root->right);
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
plant* planttree::findBestNutrition() const
{
	return findBestN(myRoot);
}
plant* planttree::findBestN(treenode* root) const
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else
	{
		plant* left = (findBestN(root->left) == nullptr) ? &(root->p) : findBestN(root->left);
		plant* right = (findBestN(root->right) == nullptr) ? &(root->p) : findBestN(root->right);
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
