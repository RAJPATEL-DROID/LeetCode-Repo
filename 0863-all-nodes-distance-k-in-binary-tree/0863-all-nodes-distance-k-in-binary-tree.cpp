/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void mark_Parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front(); q.pop();
                        
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        mark_Parents(root,parent_track);
        
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        
        int curr_level =0;
        
        while(!q.empty()){
            int sz = q.size();
                if(curr_level++ == k)break;
            for(int i=0; i< sz; i++){
                TreeNode* curr = q.front(); 
                q.pop();
                
                
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};