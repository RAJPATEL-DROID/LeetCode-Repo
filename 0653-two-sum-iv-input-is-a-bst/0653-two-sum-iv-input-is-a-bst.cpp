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
    bool dfs(TreeNode* root,int target,unordered_map<int,int>& m){
        if(root == NULL)return false;
        if(dfs(root->left,target,m))return true;
        if(m[root->val] <=0)m[root->val]++;
        if(m.find(target-root->val) != m.end()){
            if(root->val != target-root->val){
                return true;
            };            
        }
        if(dfs(root->right,target,m)){
            // cout<<"HI\n";
            return true;
        }
        return false;
    }
  
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> m;
        if(!root->left && !root->right)return false;
        return dfs(root,k,m);
    }
};