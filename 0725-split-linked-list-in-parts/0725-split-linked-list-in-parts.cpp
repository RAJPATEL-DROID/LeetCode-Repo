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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        
        int len =0;
        ListNode* curr=head;
        while(curr){
            len++;
            curr = curr->next;
        }
        
        int parts = len/k;
        int extra = len % k;
        
        curr = head;
        ListNode* prev = nullptr;
        
        for(int i=0;curr &&  i< k; i++,extra--){
            ans[i] = curr;
            for(int j=0;j < parts + (extra > 0); j++){
                prev = curr;
                if(curr)curr= curr->next;
            }
            prev->next = nullptr;
        }
        return ans;
    }
    
};