//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node* solve(int in[],int inStart,int inEnd,int post[],int postStart,int postEnd,unordered_map<int,int>& m){
    if(inStart>inEnd || postStart> postEnd)return NULL;
    
    Node* root = new Node(post[postEnd]);
    int eleIn = m[root->data];
    int nEle = eleIn - inStart;
    
    root->left = solve(in,inStart,eleIn-1,post,postStart,postStart+nEle-1,m);
    root->right = solve(in,eleIn+1,inEnd,post,postStart+nEle,postEnd-1,m);
    
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postStart = 0, postEnd = n-1;
    int inStart = 0, inEnd = n-1;
    
    unordered_map<int,int> m;
    
    for(int i=0; i < n; i++){
        m[in[i]] = i;
    }
    
    return solve(in,inStart,inEnd,post,postStart,postEnd,m);
}
