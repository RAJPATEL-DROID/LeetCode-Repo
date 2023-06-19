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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return ans;
        bool reverse = true;
        queue<TreeNode*>q;
        q.push(root);
        stack<int> s;
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            
            for(int i=0; i < sz; i++){
            TreeNode* node = q.front(); q.pop();
                if(reverse){
                    level.push_back(node->val);
                }else{
                    s.push(node->val);
                    // cout<<node->val<<" ";
                }
                if(node->left != nullptr)q.push(node->left);
                if(node->right != nullptr)q.push(node->right);
                
            }
            
            while(!s.empty()){
                level.push_back(s.top());
                s.pop();
            }
            ans.push_back(level);
            reverse = !reverse;
        }
        return ans;
    }
};