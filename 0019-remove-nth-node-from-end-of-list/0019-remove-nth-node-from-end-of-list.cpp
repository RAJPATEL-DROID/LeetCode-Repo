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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt =0;
        while(cnt<n){
            fast = fast->next;
            cnt++;
        }
        if(!fast){return head->next;}
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
         slow->next = slow->next->next;
        //slow->next = slow->next->next;
        
        return head;
        
        // ListNode *fast = head, *slow = head;
        // for (int i = 0; i < n; i++) fast = fast->next;
        // if (!fast) return head->next;
        // while (fast->next) fast = fast->next, slow = slow->next;
        // slow->next = slow->next->next;
        // return head;
    }
};