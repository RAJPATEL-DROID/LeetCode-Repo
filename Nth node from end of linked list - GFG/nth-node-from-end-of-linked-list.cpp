//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* fast = head;
       Node* slow = head;
       
       // Move the fast ptr to n node 
    //   while(n>0){
    //         if(fast!=NULL)fast = fast->next;
    //         else
    //             return -1;
    //         n--;
    //   }
       
    //   // if n is len of list then our head is the nth from last 
    //   if(fast == NULL)return head->data;
       
    //   // from nth position we move suppose x untill fast become NULL
    //   // so  x + n = L
    //   // so  x = L-n : so x is the dist of nth node from last  from the head node
    //   // so our slow will be at nth node from last when fast becomes null
    //   while(fast){
    //       fast = fast->next;
    //       slow = slow->next;
    //   }
    //   return slow->data;
        
        // In 1 iteration
        
        while(fast){
            if(n>0){
                fast = fast->next;
                n--;
            }else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(n>0)return -1;
        return slow->data;
}

