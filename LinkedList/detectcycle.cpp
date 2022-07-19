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
bool detectcycle(Node *head)
{
    if(head == NULL)
            return false;
        
    Node *fast = head;
    Node *slow = head;
        
	
    while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        
    return false;
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
    bool ans=detectcycle(head);
    ans?cout<<"Yes Cycle Present":cout<<"No cycle";
	
	return 0;
}


//TC -> o(n) where n is no of nodes
//SC -> o(1)

//@soubhik
