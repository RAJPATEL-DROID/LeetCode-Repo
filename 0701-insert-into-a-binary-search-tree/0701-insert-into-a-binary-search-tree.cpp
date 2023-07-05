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
//     TreeNode* search(TreeNode* root,int val){
//         TreeNode* temp = root;
//         while(temp){
//             if(temp->val == val)return temp;
            
//             if(temp->val > val){
//                 if(temp->left)temp = temp->left;
//                 else break;
//             }else{
//                 if(temp->right)temp =temp->right;
//                 else break;
//             }
//         }
//         return temp;
//     }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        // TreeNode* res = search(root,val);
        // if(res->val != val){
        //     TreeNode* temp = new TreeNode(val);
        //     if(res->val > val){
        //         res->left = temp;
        //     }else
        //     {
        //         res->right = temp;
        //     }
        // }
        // return root;
        
        
        
        auto curr = root;
        
        while(true){
            if(curr->val < val){
                if(curr->right) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
    
};