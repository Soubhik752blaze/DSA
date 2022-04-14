// Question:- Given a tree, Print its Zig Zag Traversal.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Binary Tree node
class Node {
public:
	int data;
	Node *left, *right;
};

// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root) 
{
	if(root == NULL)
        return { }; 
    queue <Node *> q;
    vector<int> ans;
    bool flag=false;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for(int i=0;i<size;i++)
           {
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->data);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL) 
                    q.push(temp->right);
           }
        flag=!flag;
        if(flag==false)
                reverse(level.begin(),level.end());    
        for(int i =0;i<level.size();i++)
            ans.push_back(level[i]);

    }
    return ans;
}

// A utility function to create a new node
struct Node* newNode(int data)
{
	struct Node* node = new struct Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{

	vector<int> v;

	// create tree
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	cout << "ZigZag Order traversal of binary tree is \n";

	v = zigZagTraversal(root);

	for (int i = 0; i < v.size();i++)
     {
		cout << v[i] << " ";
	}

	return 0;
}
