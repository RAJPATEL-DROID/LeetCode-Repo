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
    TreeNode* solve(vector<int>& pre,int l,int r){
        if(l > r)return NULL;
        TreeNode* root = new TreeNode(pre[l]);
        int i = l + 1;
        
        while(i <= r && pre[i] < pre[l])i++;
        
        root->left = solve(pre,l+1,i-1);
        root->right = solve(pre,i,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)return nullptr;
        
        return solve(preorder,0,preorder.size()-1);
    }
};