//Quesion:- Write an Iterative C++ program to reverse a linked list.
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
}
Node *reverseLL(Node *head)
{
    if(!head)
        return head;
    if (!head->next) return head;
    Node *curr=head;
    Node *prev=NULL;
    Node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
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
	head= reverseLL(head);
	cout << "\nReversed Linked list \n";
	printLL(head);
	return 0;
}


//TC -> o(n) where n is no of nodes
//SC -> o(1)

//@soubhik