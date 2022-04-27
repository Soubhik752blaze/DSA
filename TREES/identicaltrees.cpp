/* QUESTION:- Given 2 Tress, find whethter they are identical  */

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


int checktrees(node* p,node* q)
{
    if(p==NULL && q==NULL)
        return 1;
    else 
        if(p!=NULL && q != NULL)
        return (p->data==q->data)&&checktrees(p->left,q->left)&&checktrees(p->right,q->right); 
    
    return 0;
    

}

int identicaltrees(node *p,node *q)
{
    if (checktrees(p,q))
        return 1;
    else 
        return 0;    

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
    node *root1 = newNode(1);

    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->right->left = newNode(16);
    root1->right->left->right = newNode(30);
    
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    node *root2 = newNode(1);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->right->left = newNode(16);
    root2->right->left->right = newNode(30);
    
    root2->left->left = newNode(4);
    //root2->left->right = newNode(5);



    cout << "Are they identical trees ? Ans:- " << (identicaltrees(root1,root2)?"yes":"no");
    return 0;
}
