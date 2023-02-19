//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
Node* mergeList(Node* head1,Node* head2);
void splitList(Node* head,Node** Ahead,Node** Dhead);
void reverseList(Node*& head);
// your task is to complete this function
void sort(Node **head)
{
    Node* Ahead,*Dhead;
    splitList(*head,&Ahead,&Dhead);
    
    reverseList(Dhead);
    
    *head = mergeList(Ahead,Dhead);
}

void reverseList(Node*& head){
    Node* prev = NULL,*curr = head,*next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node* mergeList(Node* head1,Node* head2){
    if(!head1)return head2;
    if(!head2)return head1;
    
    Node* temp =NULL;
    if(head1->data < head2->data){
        temp = head1;
        head1->next = mergeList(head1->next,head2);
    }
    else{
        temp = head2;
        head2->next = mergeList(head1, head2->next);
    }
    return temp;
}

void splitList(Node* head,Node** Ahead,Node** Dhead){
    *Ahead = new Node(0);
    *Dhead = new Node(0);
    
    Node* ascn = *Ahead;
    Node* dscn = *Dhead;
    Node* curr = head;
  
    // Link alternate nodes
    while (curr) {
        // Link alternate nodes of ascending linked list
        ascn->next = curr;
        ascn = ascn->next;
        curr = curr->next;
  
        // Link alternate nodes of descending linked list
        if (curr) {
            dscn->next = curr;
            dscn = dscn->next;
            curr = curr->next;
        }
    }
  
    ascn->next = NULL;
    dscn->next = NULL;
    *Ahead = (*Ahead)->next;
    *Dhead = (*Dhead)->next;
}