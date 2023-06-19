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
    
//     int height(TreeNode* root){
//         if(root == nullptr)return 0;
        
//         int left = height(root->left);
//         int right = height(root->right);
//         return 1 + max(left,right);
//     }
    
    int dfs(TreeNode* root){
        if(root == nullptr)return 1;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l == -1 || r == -1 || (abs(l-r) > 1)){
            return -1;
        }
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
//         if(root == nullptr)return 1;
//         int left= height(root->left);
//         int right = height(root->right);
        
//         return (abs(left-right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        
        return dfs(root) != -1;
    }
};