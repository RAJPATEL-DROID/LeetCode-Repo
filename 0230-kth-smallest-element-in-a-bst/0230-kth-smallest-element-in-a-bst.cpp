/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 1. Priority Queue
// class Solution {
// public:
//     struct comparator {
//         bool operator()(int a,int b)
//             {
//                 return a>b; //ascending (Min Heap) //priority queue is ulta
//             }
//     };
    

//     void preorder(TreeNode* root, priority_queue <int,vector<int>, comparator>& q){
//         if(root==NULL) return;
//         q.push(root->val);
        
//         preorder(root->left,q);
//         preorder(root->right,q);
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         priority_queue <int,vector<int>, comparator> q;
//         preorder(root,q);
        
//         while(--k)
//             q.pop();

        
//         return q.top();
        
//     }
// };
// 2) DFS
class Solution {
public:
     int kthSmallest(TreeNode* root, int k) 
     {
        int count = countNodes(root->left);
        
        //If the number of terms on left is one less than k -> The current term is the answer
        if(k==count+1)
        return root->val;
         
         //The kth smallest element lies in the left side of the tree
        if (k <= count) 
        {
            return kthSmallest(root->left, k);
        } 
        //The kth smallest is on the right hand side 
        else if (k > count + 1) 
        {
            // count is terms on left of current node
            // 1 is to account the current node as well
            return kthSmallest(root->right, k-1-count);
        }
        return 1;
    };    
    inline int countNodes(TreeNode* n) {
        return n == NULL ? 0 : ( 1 + countNodes(n->left) + countNodes(n->right) );
    }
        
};
// // 3) Stack
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> s;
        
//         while (root != NULL) 
//         {
//             s.push(root);
//             root = root->left;
//         }
            
//         while (k--)
//         {
//             TreeNode* curr = s.top(); s.pop();

//             //If  k is zero then we reached answer
//             if (k == 0) return curr->val;
            
//             //Else find if right exists and then excplore all left branches of it
//             TreeNode* right = curr->right;
//             while (right != NULL) 
//             {
//                 s.push(right);
//                 right = right->left;
//             }
//         }
        
//         return -1; // never hit if k is valid
//     }
// };
