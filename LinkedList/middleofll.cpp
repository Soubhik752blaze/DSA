//Quesion:- Write an C++ program to find the middle of a linked list.
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int val;
	struct Node* next;
	Node(int data)
	{
		this->val = data;
		next = NULL;
	}
};
Node *addnode(Node *head, int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    head=temp;
    return head;
}
void printLL(Node* head)
{
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
        }
    cout<<endl;
}
void middleofLL(Node *head)
{
    if(!head){
        cout<<"No nodes";
        return;
    }
    if (!head->next){
        cout<<head->val;
        return;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle Node is :- ";
    cout<<slow->val;
    return;

}




/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head = new Node(5);
    head=addnode(head,4);
    head=addnode(head,3);
    head=addnode(head,2);
    head=addnode(head,1);
	cout << "Given linked list\n";
	printLL(head);
    middleofLL(head);
	
	return 0;
}


//TC -> o(n) where n is no of nodes
//SC -> o(1)

//@soubhik
//BF -> 2 times pass, 1st time take count and 2nd time go for n/2th node value.