//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
    // Reverse the LinkedList
    Node* Reverse(Node* head){
        Node* prev = NULL;
        Node* nxt = NULL;
        
        while(head != NULL){
            nxt = head->next;
            head->next= prev;
            prev= head;
            head = nxt;
        }
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // O(N) space complexity as Each Char of String will be stored somewhere
        // string s="";
        // while(head != NULL){
        //     s += head->data;
        //     head = head->next;
        // }
        
        // for(int i=0;i<s.length();i++){
        //     if(s[i] != s[s.length()-i-1]){
        //         return false;
        //     }
        // }
        // return true;
        
        // O(1) Time Complexity
        if(head==NULL||head->next==NULL) return true;
        Node* fast = head;
        Node* slow = head;
        Node* pal = head;
        
        while(fast !=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
           
        }
        
        slow = Reverse(slow);
        
        while(slow != NULL){
            if(slow->data != pal->data)return false;
            slow = slow->next;
            pal = pal->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends