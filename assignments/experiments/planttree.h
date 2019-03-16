#ifndef PLANTTREE_H
#define PLANTTREE_H
#include "plant.h"
#include <cstring>
/*
- planttree -- This is a tree that holds the plant data. Each non-leaf node in
  this tree will have exactly two children. The children are not sorted in any
  way. The planttree class has a method for setting the root of the tree as
  well as setting the children for a given node. See the experiments.cpp file
  to see what the method signature is for each of these.

- treenode -- this will be a class (or struct, your choice) to hold a plant
  object and the two children pointers
*/

class planttree
{
	private:
		//treenode struct
		struct treenode
		{
			plant p;
			treenode* left;
			treenode* right;
			//constructor and destructor
			treenode(const plant & p1)
			{
				left = nullptr;
				right = nullptr;
				p = p1;
			}
			~treenode()
			{
				delete left;
				delete right;
			}
		};
		treenode* myRoot;

		void preOrderPrint(treenode*, int);
		//findBest functions - might need to make public without ptr arg
		plant* findBestGrowth(treenode*) const;
		plant* findBestNutrition(treenode*) const;
		plant findBestWater(treenode*) const;
		
		//copy function for tree
		treenode* copyTree(treenode* root)
		{
			if(root == nullptr)
			{
				return nullptr;
			}
			else
			{
				treenode* n = new treenode(root->p);//maybe switch to just "node"
				n->left = copyTree(root->left);
				n->right = copyTree(root->right);
				return n;
			}
		}
		//search function for tree
		treenode* search(treenode* root, char* ID)
		{
			int temp;
			if(root != nullptr)
			{
				if(std::strncmp(root->p.getID(), ID, strlen(ID)+1) == 0)
				{
					temp = root;
				}
				search(root->left, ID);
				search(root->right, ID);
			}
			else
			{
				temp = nullptr;
			}
		return temp;
		}

	public:
		planttree();
		~planttree();
		planttree(const planttree&);
		planttree& operator=(const planttree&);
		void setRoot(const plant&);
		void addChildren(const plant&);
		void display();
		//might need to add public findBest functions
};
#endif