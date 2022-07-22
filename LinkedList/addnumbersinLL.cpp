//Quesion:- Write an C++ program to add 2 numbers given in form of 2 linked lists.
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
    //main function
Node* addnumbersinLL(Node *l1,Node* l2)
   {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    dummy->next = temp;
    int carry=0;
    while(l1!=NULL || l2 !=NULL || carry )
    {
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry = sum / 10;
        Node* node = new Node(sum % 10);
        temp->next=node;
        temp=temp->next;

    }
    return dummy->next;
   }


/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head1 = new Node(3);
    head1=addnode(head1,4);
    head1=addnode(head1,8);

    Node *head2 = new Node(6);
    head2=addnode(head2,6);
    head2=addnode(head2,5);
	cout << "Given linked lists\n";
	printLL(head1);
    printLL(head2);

    int k=3;
    Node *head3=addnumbersinLL(head1,head2);
    cout << "New resultant Linked List is:- ";
    printLL(head3);
	
	return 0;
}


//TC -> o(max(n1,n2)) where n1,n2 are no of nodes in both LLs.
//SC -> o(1)

//@soubhik
//Asked in Amazon,Microsoft and Meta
