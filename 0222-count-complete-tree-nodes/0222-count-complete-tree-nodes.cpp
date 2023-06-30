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
    int leftHeight(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
    int rightHeight(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root = root->right;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh)return (1<<lh) -1;
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return 1 + leftNodes + rightNodes;
    }
};