//Quesion:- Write an C++ program to rotate a linked list.
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
Node *reverseLL(Node *head)
{
    if(!head || !head->next)
        return head;
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
    //main function which implements the logic
bool checkpalindromeLL(Node *head )
   {
    if(!head)           //edge_cases
        return true;
    
    Node *slow=head;
    Node *fast=head;
    Node *curr=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=reverseLL(slow);
    while(slow!=NULL){
        if(curr->val != slow->val)
            return false;
        curr=curr->next;
        slow=slow->next;
    }
    return true;
    
   }


/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head = new Node(1);
    head=addnode(head,2);
    head=addnode(head,3);
    head=addnode(head,2);
    head=addnode(head,1);

    bool ans =checkpalindromeLL(head);
    ans?cout<<"yes":cout<<"No";
	
	return 0;
}


//TC -> o(n/2) where n is no of nodes in LL.
//SC -> o(1)

//@soubhik
//BF -> o(n),o(n)
//Asked in Amazon,Adobe and snapdeal
