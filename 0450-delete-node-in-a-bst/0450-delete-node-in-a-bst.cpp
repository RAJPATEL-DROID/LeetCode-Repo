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
    TreeNode* findRight(TreeNode* root){
        if(root->right == NULL)return root;
        return findRight(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL)return root->right;
        else if(root->right == NULL)return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int x) {
        if(root == NULL)return NULL;
        if(root->val == x)return helper(root);
        
        TreeNode* temp = root;
        while(temp!= NULL){
            if(temp->val > x){
                if(temp->left != NULL && temp->left->val == x){
                    temp->left = helper(temp->left);
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right != NULL && temp->right->val == x){
                    temp->right = helper(temp->right);
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};