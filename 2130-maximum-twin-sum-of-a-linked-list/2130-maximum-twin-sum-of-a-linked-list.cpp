/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> s;
        ListNode* temp = head;
        while(temp != NULL){
            s.push_back(temp->val);
            temp = temp->next;
        }
        int ans =0;
        for(int i=0;i < s.size()/2;i++){
            ans = max(ans,s[i] + s[s.size()-1-i]);
        }
        return ans;
        
    }
};