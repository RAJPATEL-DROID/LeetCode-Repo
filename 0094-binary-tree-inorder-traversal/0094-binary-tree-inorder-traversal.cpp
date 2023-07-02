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
    // vector<int> ans;
    // void dfs(TreeNode* Node){
    //     if(Node==nullptr){return;}

    //     dfs(Node->left);
    //     ans.push_back(Node->val);
    //     dfs(Node->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     dfs(root);
    //     return ans;        
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> inorder;
        // stack<TreeNode*> s;
        // TreeNode* node = root;
        // // s.push(node);
        // while(true){
        //     if(node != NULL){
        //         s.push(node);
        //         node = node->left;
        //     }else{
        //         if(s.empty()==true){
        //             break;
        //         }
        //         node =s.top();
        //         s.pop();
        //         inorder.push_back(node->val);
        //         node = node->right;
        //     }
        // }
        // return inorder;
        
        // Morris Order Traversal 
        // Uses Threaded Binary Trees(Threading Most Right node of Left subtree with root)
        vector<int> inorder;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;

                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }


};