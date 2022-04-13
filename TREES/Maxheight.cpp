/* QUESTION:- Given a binary tree, find height of it. 
Height of empty tree is -1, height of tree with one node is 0. */

// C++ program to find height of tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
    int data;
    node* left;
    node* right;
};


int maxDepth(node* root)
{
    if(!root)
        return -1;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh,rh);    

}


node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
// Driver code   
int main()
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(16);
    root->right->left->right = newNode(30);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Height of tree is " << maxDepth(root);
    return 0;
}
