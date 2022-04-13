/* QUESTION:- Given a binary tree, find whether it is a balanced tree or not
A balanced tree has the following condition : - For every node, the height diff of left and right subtree can at max be 1 */

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

int checkheight(node* root)
{
    if(!root)
        return 0;

    int lh = checkheight(root->left);
    if (lh == -1)
        return -1;
    int rh = checkheight(root->right);
    if (rh == -1)
        return -1;

    if(abs(lh-rh)>1)
        return -1;    

    return 1 + max(lh,rh);    

}

string checkBalanceTree(node* root)
{
    return (checkheight(root)!= -1) ? "True" : "False";
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
    cout << "Is Tree Balanced -> " << checkBalanceTree(root);
    return 0;
}
