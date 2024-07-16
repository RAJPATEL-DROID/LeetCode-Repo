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
TreeNode* findLCA(TreeNode* root,int start,int dest){
    if(root == NULL)return NULL;

    if(root->val == start || root->val == dest)return root;

    TreeNode* left = findLCA(root->left,start,dest);
    TreeNode* right = findLCA(root->right,start,dest);

    if(left && right)return root;

    return left ?left : right;
}

    bool traverse(TreeNode* root,string& str,int val){
        if(!root)return false;

        if(root->val == val)return true;

        str.push_back('L');
        if(traverse(root->left,str,val))return true;

        str.pop_back();

        str.push_back('R');
        if(traverse(root->right,str,val))return true;

        str.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root,startValue,destValue);

        string lca_to_start ="",lca_to_dest="";

        traverse(lca,lca_to_start,startValue);
        traverse(lca,lca_to_dest,destValue);

        for(char& c : lca_to_start){
            c = 'U';
        }

        return lca_to_start + lca_to_dest;
    }
};