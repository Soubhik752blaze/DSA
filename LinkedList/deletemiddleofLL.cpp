//Quesion:- Write an C++ program to find and delete the middle of a linked list.
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
Node* deletemiddleofLL(Node *head)
{
    if (!head->next){
            return NULL;
        }
        Node *slow=head;
        Node *prev;
        Node *fast=slow;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete(slow);
        return head;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head = new Node(6);
    head=addnode(head,5);
    head=addnode(head,4);
    head=addnode(head,3);
    head=addnode(head,2);
    head=addnode(head,1);
	cout << "Given linked list\n";
	printLL(head);
    head=deletemiddleofLL(head);
	printLL(head);
	return 0;
}


//TC -> o(n) where n is no of nodes
//SC -> o(1)

//@soubhik
//BF -> 2 times pass, 1st time take count and 2nd time go for (n/2 - 1)th node value. and do the necessary prev->next=curr->next and all 