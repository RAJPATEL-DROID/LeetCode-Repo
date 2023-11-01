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
    void solve(TreeNode* root,unordered_map<int,int>& mp){
        if(root== NULL)return;
        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        solve(root,mp);
        int maxi = 0;
        vector<int> ans;
        for(auto it: mp){
            if(it.second > maxi){
                maxi = it.second;
                while(ans.size() > 0)ans.pop_back();
                ans.push_back(it.first);
            }else if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};