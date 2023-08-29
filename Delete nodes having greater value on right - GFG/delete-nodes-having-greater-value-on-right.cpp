//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        // vector<int> a;
        
        // Node* temp = head;
        // while(temp != NULL){
        //     a.push_back(temp->data);
        //     temp = temp->next;
        // }
        
        // for(int i = a.size()-2; i>=0 ;i--){
        //     if( a[i] < a[i+1] ){
        //         a[i] = a[i+1];
        //     }
        // }
        
        // temp = new Node(a[0]);
        // head = temp;
        // for(int i=1; i < a.size(); i++){
        //     if(a[i] != a[i-1]){
        //         Node* t = new Node(a[i]);
        //         temp->next = t;
        //         temp = temp->next;
        //     }
        // }
        // temp->next = NULL;
        // return head;
        
        if(head->next == NULL)return head;
        else{
            Node* temp = compute(head->next);
            if(head->data >= temp->data){
                head->next = temp;
                return head;
            }else{
                return temp;
            }
        }
        
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends