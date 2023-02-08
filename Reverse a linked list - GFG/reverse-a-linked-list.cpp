//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    // Recursive Method for changing the pointer of a node
    struct Node* Recursive(struct Node* node){
        if(node == NULL || node->next == NULL)return node;
        Node* nextNode = Recursive(node->next);
        node->next->next = node;
        node->next = NULL;
        return nextNode;
        
    }
    
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
    
    // Iterative Method
        // Node* curr = head;
        // Node* frwd = curr->next;
        // Node* prev = head;
        // curr->next = NULL;
        
        // while(frwd != NULL){
        //     prev  = curr;
        //     curr = frwd;
        //     frwd = curr->next;
        //     curr->next = prev;
        // }
        // return curr;
        

    // Recursive Method
        struct Node* newHead = Recursive(head);
        return newHead;
        
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends