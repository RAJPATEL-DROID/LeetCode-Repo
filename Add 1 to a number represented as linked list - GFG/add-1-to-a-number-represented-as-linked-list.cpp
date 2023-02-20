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
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    
    // RECURSIVE METHOD for ADDING 1
    // int addRecursive(Node* head){
    //     // base case
    //     if(head==NULL)return 1;
        
    //     int carry = addRecursive(head->next);
    //     int curr = head->data + carry;
    //     head->data = curr%10;
    //     return (curr/10);
    // }

    // Node* addOne(Node *head) 
    // {
    //     // Your Code here
    //     // return head of list after adding one
    //     int carry = addRecursive(head);
        
    //     if(carry){
    //         Node* newNode = new Node(carry);
    //         newNode->next = head;
    //         head = newNode;
    //     }
    //     return head;
        
    // }


    // Reverse the List and add 
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* next = head->next;
        Node* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node* head){
        head = reverse(head);
        Node* temp = head;
        
        while(temp != NULL){
            if(temp->next == NULL && temp->data == 9){
                temp->data = 1;
                Node* newNode = new Node(0);
                newNode->next = head;
                head = newNode;
                temp = temp->next;
            }else if(temp->data == 9){
                temp->data =0;
                temp = temp->next;
            }else{
                temp->data = temp->data + 1;
                break;
            }
        }
        head = reverse(head);
        return head;
    }

};  

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends