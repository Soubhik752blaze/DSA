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
    //main function which implements the logic
Node* rotateLL(Node *head,int k )
   {
    if(!head || head->next==NULL || k==0)           //edge_cases
        return head;
    
    Node *curr=head;
    int n=1;
    while(curr->next!=NULL){
        curr=curr->next;
        n++;
    }

    //to go till that node
    k = k % n;
    if(!k)
        return head;                //if k==0 then no rotation needed
    curr->next=head;
    k = n - k; 
    while(k--)
        curr=curr->next;
        
    head=curr->next;
    curr->next=NULL;

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

    head=rotateLL(head,4);
    cout << "New resultant Linked List is:- ";
    printLL(head);
	
	return 0;
}


//TC -> o(max(n1,n2)) where n1,n2 are no of nodes in both LLs.
//SC -> o(1)

//@soubhik
//BF -> o(k x n)
//Asked in Amazon,Microsoft and Adobe
