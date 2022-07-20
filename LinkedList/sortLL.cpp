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
Node* mergelist(Node *l1, Node *l2)
    {
        Node *ptr = new Node(0);
        Node *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }

Node* sortLL(Node* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        Node *temp = NULL;
        Node *slow = head;
        Node *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        Node* l1 = sortLL(head);    //left half recursive call
        Node* l2 = sortLL(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
    


/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node *head = new Node(5);
    head=addnode(head,3);
    head=addnode(head,1);
    head=addnode(head,2);
    head=addnode(head,4);
	cout << "Given linked list\n";
	printLL(head);
    head=sortLL(head);
    cout << "After sorting\n";
    printLL(head);
	
	return 0;
}


//TC -> o(nlogn) where n is no of nodes
//SC -> o(1)

//@soubhik
