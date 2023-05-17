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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode* curr = head;
        ListNode* frwd = curr->next;
        ListNode* prev = NULL;
        curr->next = prev;
        
        while(frwd!= NULL){
            prev = curr;
            curr = frwd;
            frwd = curr->next;
            curr->next = prev;
        }
        return curr;
    }
    int pairSum(ListNode* head) {
        // vector<int> s;
        ListNode* temp = head;
        // while(temp != NULL){
        //     s.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int ans =0;
        // for(int i=0;i < s.size()/2;i++){
        //     ans = max(ans,s[i] + s[s.size()-1-i]);
        // }
        // return ans;
        
        
        ListNode* fast = head;
        
        while(fast->next->next && fast->next){
            fast = fast->next->next;
            temp = temp->next;
        }
        temp->next = reverseList(temp->next);
        // cout<<temp->next->val;
        fast = temp->next;
        temp = head;
        int ans =0;
        
        while(fast){
            ans = max(ans,temp->val+fast->val);
            fast = fast->next;
            temp = temp->next;
        }
        return ans;     
        
    }
};