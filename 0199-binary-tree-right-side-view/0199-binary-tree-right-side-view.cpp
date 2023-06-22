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
    //  void recursion(TreeNode *root, int level, vector<int> &res)
    // {
    //     if(root==NULL) return ;
    //     if(res.size()<level) res.push_back(root->val);
    //     recursion(root->right, level+1, res);
    //     recursion(root->left, level+1, res);
    // }
    
    vector<int> rightSideView(TreeNode *root) {
//         vector<int> res;
//         recursion(root, 1, res);
//         return res;
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            while(s-- > 0) {
                TreeNode *curr = q.front();
                q.pop();
                if(s == 0) {
                    ans.push_back(curr->val);
                }
                
                if(curr->left) {
                    q.push(curr->left);
                } 
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};