//-------------------------------------------------------------
//Check to see if bst is identical to other bst
//struct to store bst node
struct node
{
	int key;
	node* left, *right;
};
//recursive funct to check identical
int isIdentical(node* x, node *y)
{
	//if empty return true
	if(x == y && y == nullptr)
	{
		return 1;
	}
	//if not empty and root matches
	return(x && y) && (x-key == y->key) && isIdentical(x->left, y->left) && isIdentical(x->right, y->right);
}

//-------------------------------------------------------------
//find height of bst
int height(node* root)
{
	//base case: empty tree has height of 0
	if(root == nullptr)
	{
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

//-------------------------------------------------------------
//delete bst

//struct to store bt node
struct node
{
	int key;
	node *left, *right;
};
void deleteBinaryTree(node* &root)
{
	if(root == nullptr)
	{
		return;
	}
	//using postorder
	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);
	delete root;
	root = nullptr;
}	

//-------------------------------------------------------------
//treaverse bst pre, post, and inorder 
void inorder(node* root)
{
	if(root == nullptr)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preorder(node* root)
{
	if(root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root-right);
}
void postorder(node* root)
{
	if(root == nullptr)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

//-------------------------------------------------------------
//find min value in tree, the leftmost leaf
node* minValueNode(node* node)
{
	node* curr = node;

	while(curr->left != nullptr)
	{
		curr = curr->left;
	}
	return curr;
}
//-------------------------------------------------------------
//delete node in bst, by a given key
deletenode(node* root, int key)
{
	if (root == nullptr)
	{
		return;
	}
	//if key is smaller, go left
	if(key < root->data)
	{
		root->left = deletenode(root->left, key);
	}
	//if greater, go right
	else if(key > root->data)
	{
		root->right = deletenode(root->right, key);
	}
	//if equal, delete
	else
	{
		//node with one child
		if(root->left == nullptr)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == nullptr)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		
		//if two childern, inorder successor
		node *temp = minValueNode(root->right);
		//copy inorder successor into node, overwritting node
		root->data = temp->data;
		//delete inorder successor
		root->right = deletenode(root->right, temp->data);
	}
	return root;
}
//-------------------------------------------------------------

