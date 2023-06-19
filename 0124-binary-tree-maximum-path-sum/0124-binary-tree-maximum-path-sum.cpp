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
    int findPathSum(TreeNode* root,int& ans){
        if(root == nullptr)return 0;
        
        int left = findPathSum(root->left,ans);
        int right= findPathSum(root->right,ans);

        ans = max(ans, root->val + left + right);
        return max(0, root->val + max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findPathSum(root,ans);
        return ans;
    }
};