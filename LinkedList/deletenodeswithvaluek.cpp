//Quesion:- Write an C++ program to sort a linked list.
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
    //MergeSort Function O(n*logn)
Node* deletenodewithvaluek(Node *head, int k)
   {
    if(!head)   return head;
    Node* del=head;
    while(head->val==k)
    {
        del=head;
        head=head->next;
        delete(del);
    }
    Node* temp=head;
    while(temp && temp->next)
    {
        if(temp->next->val==k)
        {
            del=temp->next;
            temp->next=temp->next->next;
            delete(del);
        }
        else
            temp=temp->next;
    }
    return head;

   }


/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head = new Node(1);
    head=addnode(head,2);
    head=addnode(head,2);
    head=addnode(head,3);
    head=addnode(head,1);
	cout << "Given linked list\n";
	printLL(head);
    int k=3;
    head=deletenodewithvaluek(head,2);
    cout << "After deleting nodes with value k\n";
    printLL(head);
	
	return 0;
}


//TC -> o(n) where n is no of nodes
//SC -> o(1)

//@soubhik
