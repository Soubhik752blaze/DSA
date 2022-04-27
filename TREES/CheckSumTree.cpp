// Write a function that returns true if the given Binary Tree is SumTree else false. 
//A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree.
// An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
	    int data;
	    node* left;
	    node* right;
};

/* Utility function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;
	return 0;
}


int isSumTree(node* node)
{
	int ls; 
    int rs;

	if(node == NULL || isLeaf(node))
		return 1;

	if( isSumTree(node->left) && isSumTree(node->right))
	{
	
		// Get the sum of nodes in left subtree
		if(node->left == NULL)
			ls = 0;
		else if(isLeaf(node->left))
			ls = node->left->data;
		else
			ls = 2 * (node->left->data);

		
		if(node->right == NULL)
			rs = 0;
		else if(isLeaf(node->right))
			rs = node->right->data;
		else
			rs = 2 * (node->right->data);

		/* If root's data is equal to sum of nodes in left
		and right subtrees then return 1 else return 0*/
		return(node->data == ls + rs);
	}
	return 0;
}


node* newNode(int data)
{
	node* node1 = new node();
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;
	return(node1);
}

/* Driver code */
int main()
{
	node *root = newNode(26);
	root->left = newNode(10);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->right->right = newNode(3);
	if(isSumTree(root))
		cout << "The given tree is a SumTree ";
	else
		cout << "The given tree is not a SumTree ";
	return 0;
}

// This code is contributed by rutvik_56
