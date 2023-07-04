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
class Solution {
public:
    TreeNode* prev= NULL;
    void flatten(TreeNode* root) {
              
// ------------------------------------------RECURSIVE ---------------------------------------------
        
    // Just impplementing reverse postorder traversal and making connections
    
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
        
// ----------------------------------------- ITERATIVE ----------------------------------------------
        
        // stack<TreeNode*>s;
        // s.push(root);
        // while(!s.empty()) {
        //     TreeNode * curr = s.top();
        //     s.pop();
        //     if(curr->right) {
        //         s.push(curr->right);
        //     }
        //     if(curr->left){
        //         s.push(curr->left);
        //     }
        //     if(!s.empty()) {
        //         curr->right = s.top();
        //     }
        //     curr->left = NULL;
        // }
        
        
        // SC : O(1)
//         TreeNode* curr = root;
        
//         while(curr != NULL){
//             if(curr->left != NULL){
//                 TreeNode* prev = curr->left;
//                 while(prev->right){
//                     prev = prev->right;
//                 }
//                 prev->right = curr->right;
//                 curr->right = curr->left;
//                 curr->left = NULL;
//             }
//             curr = curr->right;
//         }
    }
};