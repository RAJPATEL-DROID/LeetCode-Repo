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

    void inorder(TreeNode* root,vector<int>& inr){
        if(!root)return;

        inorder(root->left,inr);

        inr.push_back(root->val);

        inorder(root->right,inr);

    }

    TreeNode* constructBinaryTree(vector<int>& inr,int l,int r){

        if(l > r)return NULL;

        int mid = (l + r) >> 1;

        TreeNode* current = new TreeNode(inr[mid]);

        current->left = constructBinaryTree(inr,l,mid-1);
    
        current-> right = constructBinaryTree(inr,mid+1,r);

        return current;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> inr;
        inorder(root,inr);

        return constructBinaryTree(inr,0,inr.size()-1);
    }
};