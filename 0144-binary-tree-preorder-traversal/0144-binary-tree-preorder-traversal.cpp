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

    vector<int> preorderTraversal(TreeNode* root){
//         vector<int> preorder;
//         stack<TreeNode*> s;
//         if(root==NULL)return preorder;
//         s.push(root);
//         while(!s.empty()){
//             root = s.top();s.pop();
//             preorder.push_back(root->val);

//             if(root->right!=NULL){s.push(root->right);}
//             if(root->left != NULL){s.push(root->left);}

//         }
//         return preorder;
        vector<int> preorder;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;

                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }

    // Recursive Method
    // void dfs(vector<int>& v,TreeNode* root){
    //     if(root==nullptr){return;}
    //     v.push_back(root->val);
    //     dfs(v,root->left);
    //     dfs(v,root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> v;
    //     dfs(v,root);
    //     return v;
    // }
};