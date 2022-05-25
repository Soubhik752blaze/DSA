// Left View of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Binary Tree node
class Node {
public:
    int data;
    Node *left, *right;
};

void leftViewUtil(struct Node *root,
                int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left submtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);

}

// Function to print the zigzag traversal
void leftView(Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// A utility function to create a new node
Node* newNode(int data)
{
    Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

// Driver program to test
// the above function
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
    cout << "\n \n"<<"Left View of binary tree is \n";

    leftView(root);

    return 0;
}