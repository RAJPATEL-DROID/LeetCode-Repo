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
//     bool solve(TreeNode* root,long mini,long maxi){
//         if(root == NULL)return true;
//         if(root->val >= maxi || root->val <= mini)return false;
        
//         return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
//     }
//     bool isValidBST(TreeNode* root) {
//         long mini = LONG_MIN;
//         long maxi = LONG_MAX;
//         return solve(root,mini,maxi);
//     }
    
    // Use Prev Pointer to check condition,traversing in Inorder.
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};