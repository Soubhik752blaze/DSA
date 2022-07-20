//Quesion:- Write an C++ program to merge 2 sorted linked lists.
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

Node* merge2LL(Node* head1, Node* head2)
{
    if(!head1)  return head2;
    if(!head2)  return head1;
    if(head1->val>=head2->val)  swap(head1,head2);
    Node* headLL = head1;
    while(head1!=NULL && head2!=NULL){
        Node* temp = NULL;
        while(head1!=NULL && head1->val<head2->val)
        {
            temp=head1;
            head1=head1->next;
        }
        temp->next=head2;   //link change and then swap l1,l2
        swap(head1,head2);
    }
    return headLL;
}

Node* merge2LLBruteForce(Node *head1,Node *head2)
{
    Node* dummy = new Node(0);
    Node* dd = NULL;
    Node* curr1 = head1;
    Node* curr2 = head2;
    if(curr1->val >= curr2->val){
        Node *temp = new Node(curr2->val);
        dummy->next=temp;
        dd=temp;
        curr2=curr2->next;
    }
    else{
        Node *temp = new Node(curr1->val);
        dummy->next=temp;
        dd=temp;
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->val >= curr2->val){
            Node *temp = new Node(curr2->val);
            dd->next = temp;
            dd=temp;
            curr2=curr2->next;
        }
        else if(curr1->val <= curr2->val){
            Node *temp = new Node(curr1->val);
            dd->next = temp;
            dd=temp;
            curr1=curr1->next;
        }        
    }
    if(curr2!=NULL)                  //while 2nd list not empty
        dd->next=curr2;
    if(curr2==NULL && curr1!=NULL)                  //while 1st list not empty
        dd->next=curr1;

    return dummy->next;
}

/* Driver code*/
int main()
{
	/* 1st list */
	Node *head1 = new Node(6);
    head1=addnode(head1,5);
    head1=addnode(head1,3);
    /* 2nd list */
    Node *head2 = new Node(4);
    head2=addnode(head2,2);
    head2=addnode(head2,1);


	cout << "Given linked lists\n";
	printLL(head1);
    printLL(head2);
    Node* res=merge2LLBruteForce(head1,head2);
    Node* res_opt=merge2LL(head1,head2);
	printLL(res);
    printLL(res_opt);
	return 0;
}


//TC -> o(n1+n2) where n is no of nodes
//SC -> o(1)

//@soubhik
//BF -> o(n1+n2) same TC,SC