//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
    
  public:
    bool isAnagram(string s,string temp){
        if(s.length() != temp.length())return false;
        
        int hashmap[26] = {0};
        for(int i =0;i<s.length();i++){
            hashmap[s[i]-'a']++;
            hashmap[temp[i]-'a']--;
        }
        
        for(int i=0; i < 26;i++){
            if(hashmap[i] != 0)return false;
        }
        return true;
    }
    
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
       if(head ==  NULL )return {};
       
       vector<Node*> ans={};
       
       Node* init =head;
       Node* last = NULL;
       
       while(head != NULL){
           
           string temp ="";
           for(int i=0;i < s.length(); i++){
               if(init == NULL)return ans;
               
               temp = temp + init->data;
               last = init;
               init = init->next;
           }
           
           if(isAnagram(s,temp)){
               ans.push_back(head);
               last->next = NULL;
           }else{
               init = head->next;
           }
           head = init;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends