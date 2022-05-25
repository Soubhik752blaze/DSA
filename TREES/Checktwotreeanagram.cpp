// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of a Tree Node
class node {
public:
	int data;
	node* left;
	node* right;
};

node* newNode(int data);

bool checktwotreesareanagram(node* p, node *q)
{
	
	if (p == NULL && q==0)
		return true;
	
    if (p == NULL || q==0)
		return false;
	
	queue < node *> q1,q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty())
    {
        vector<int> cl1,cl2;
        int n1=q1.size();
        int n2=q2.size();

        if(n1!=n2)
            return false;

        if(n1==0)
            return true;

        while(n1>0)
        {
            node *temp1 = q1.front();
            q1.pop();
            if(temp1->left != NULL)
                q1.push(temp1->left);
            if(temp1->right != NULL)
                q1.push(temp1->right); 

            n1--; 

            node *temp2 = q2.front();
            q2.pop();
            if(temp2->left != NULL)
                q2.push(temp2->left);
            if(temp2->right != NULL)
                q2.push(temp2->right);  

            cl1.push_back(temp1->data);
            cl2.push_back(temp2->data);
        }
        sort(cl1.begin(),cl1.end());
        sort(cl2.begin(),cl2.end());

        if(cl1!=cl2)
            return false;       
               
    }
    return true;
}
	
	


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return (Node);
}

// Driver Code
int main()
{
	node* root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	root1->right->left = newNode(9);
	root1->right->right = newNode(8);
	root1->left->left->left = newNode(6);
	root1->left->left->right = newNode(7);

    node* root2 = newNode(1);
	root2->left = newNode(3);
	root2->right = newNode(2);
	root2->left->left = newNode(5);
	root2->left->right = newNode(4);
	root2->right->left = newNode(8);
	root2->right->right = newNode(9);
	root2->left->left->left = newNode(7);
	root2->left->left->right = newNode(9);
    string result =(checktwotreesareanagram(root1,root2)?"Yes":"No its not!");
	cout << "Are these Trees anagrams? "<<result;
	return 0;
}


