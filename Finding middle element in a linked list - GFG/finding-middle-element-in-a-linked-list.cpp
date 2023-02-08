//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        // Node* fast = head;
        // Node* slow = head;
        
        // while(fast!= NULL && fast->next != NULL){
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }
        // // if(fast == NULL){
        // //     return slow->next->data;
        // // }
        // if(fast->next == NULL){
        //     return slow->data;
        // }
        // return slow->next->data;
        
        
        int sz =1;
        Node* node = head;
        while(node->next != NULL){
            node = node->next;
            sz++;
        }
        sz = sz/2 + 1;
        node = head;
        for(int i=1;i<sz;i++){
            node = node->next;
        }
        return node->data;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends