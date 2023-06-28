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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        
        queue<pair<TreeNode*,long long> > q;
        q.push({root,0});
        long long res =1;
        while(!q.empty()){
            int sz =q.size();
            long long start = q.front().second;
            long long end = q.back().second;
        
            res = max(res,end-start + 1);
    
            for(int i=0;i< sz;i++){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                long long idx = temp.second - start;
                
                if(temp.first->left)q.push({temp.first->left,(long long)2* idx + 1});
                if(temp.first->right)q.push({temp.first->right,(long long)2* idx + 2});               
            }           
        }
        return res;            
    }
};