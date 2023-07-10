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
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//        if (!t1 && !t2) return nullptr;
        
//         int val1 = t1 ? t1->val : 0;
//         int val2 = t2 ? t2->val : 0;
        
//         TreeNode* t = new TreeNode(val1 + val2);
//         t->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
//         t->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        
//         return t;
//     }
// };


// TC : O(N)

class Solution { // iterative: Stack
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t1 || !t2) return t1? t1:t2;
				
        stack<TreeNode*> s1,s2;
        s1.push(t1);
        s2.push(t2);
        
        while(!s1.empty()){
            TreeNode* c1(s1.top());
            TreeNode* c2(s2.top());
            s1.pop();
            s2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) c1->left = c2->left;
            else if(c1->left && c2->left) { s1.push(c1->left); s2.push(c2->left); }
            
            if(!c1->right && c2->right) c1->right = c2->right;
            else if(c1->right && c2->right) { s1.push(c1->right); s2.push(c2->right); }
        }
        return t1;
    }
};


// Iterative: Using Queue

// class Solution { // iterative: Queue    
// public:
//     TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//         if(!t1 && !t2) return nullptr;
//         if(!t1 || !t2) return t1? t1:t2;

//         queue<TreeNode*> q1,q2;
//         q1.push(t1);
//         q2.push(t2);
        
//         while(!q1.empty() && !q2.empty()){
//             TreeNode* c1(q1.front());
//             TreeNode* c2(q2.front());
//             q1.pop();
//             q2.pop();
            
//             c1->val+=c2->val;
            
//             if(!c1->left && c2->left) c1->left = c2->left;
//             else if(c1->left && c2->left) { q1.push(c1->left); q2.push(c2->left); }
            
//             if(!c1->right && c2->right) c1->right = c2->right;
//             else if(c1->right && c2->right) { q1.push(c1->right); q2.push(c2->right); }
//         }
//         return t1;
//     }
// };