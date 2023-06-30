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
    TreeNode* constructTree(vector<int>& in,int inStart,int inEnd,vector<int>& pre,int preStart,int preEnd,
        map<int,int>& mp){
        if(inStart> inEnd || preStart>preEnd)return NULL;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        int eleIn = mp[root->val];
        int nEle = eleIn - inStart;
        
        root->left = constructTree(in,inStart,eleIn - 1,pre,preStart + 1,preStart + nEle,mp);
        root->right = constructTree(in,eleIn + 1,inEnd,pre,preStart + nEle + 1,preEnd,mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int preStart =0,preEnd = pre.size()-1 ;
        int inStart = 0,inEnd = in.size()-1;
        
        map<int,int> mp;
        for(int i=0; i <= inEnd; i++){
            mp[in[i]] = i;
        }
        return constructTree(in,inStart,inEnd,pre,preStart,preEnd,mp);
    }
};