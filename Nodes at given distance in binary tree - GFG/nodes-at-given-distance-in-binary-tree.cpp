//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    void parentPointers(unordered_map<Node *, Node *> &m,Node * root){
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                if(q.front()->left){
                    q.push(q.front()->left);
                    m[q.front()->left] = q.front();
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    m[q.front()->right] = q.front();
                }
                q.pop();
            }
        }
    }

    void search(Node *root, int target,vector<Node *> &targetNode){
        if(root == NULL)return;
        
        if(root->data == target){
            targetNode.push_back(root);
            return;
        }
        search(root->left, target, targetNode);
        search(root->right, target, targetNode);
    }
    
    
public:
    
    
    vector<int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int>ans;
        if(root == NULL)return ans;
        
        //searching target node with value equal to target
        vector<Node *>targetNode;
        search(root, target, targetNode);
    
        
        //parent pointers store first-childNode, second-parentNode
        unordered_map<Node *, Node *>m;
        parentPointers(m, root);
        
        //to store the visited node values - unique values so no prblm 
        unordered_map<int,int>visit;
        
        //traversing for nodes at a distance of k
        queue<Node *>q;
        q.push(targetNode[0]);
        int distance = 0;
        
        while(!q.empty() && distance != k){
            int n = q.size();
            distance++;
            while(n--){
                Node *node = q.front();
                q.pop();
                visit[node->data]++;
                
                //checking all three directions right left top
                
                //left
                if(node->left && (visit.find(node->left->data) == visit.end()))q.push(node->left);
                
                //right
                if(node->right && (visit.find(node->right->data) == visit.end()))q.push(node->right);
                
                //top
                if(m.find(node) != m.end() && visit.find(m[node]->data) == visit.end())q.push(m[node]);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends