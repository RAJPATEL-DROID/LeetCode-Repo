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
    private:
    int findPathSum(TreeNode* root,int& maxi){
        if(root == nullptr)return 0;
        
        int l = findPathSum(root->left,maxi);
        int r= findPathSum(root->right,maxi);
        if(l < 0) l=0;
        if(r < 0) r=0;
        
        maxi  = max(maxi, root->val + l + r);
        
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findPathSum(root,ans);
        return ans;
    }
};