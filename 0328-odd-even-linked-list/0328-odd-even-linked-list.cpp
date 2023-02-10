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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL  || !head->next->next) 
            return head;
        ListNode* e_start = head->next;
        ListNode* even_curr = head->next;
        ListNode* odd_curr = head;
 
        while(odd_curr->next  && even_curr->next){
            odd_curr->next = even_curr->next;
            even_curr->next = odd_curr->next->next;
            odd_curr = odd_curr->next;
            even_curr = even_curr->next;
        }
        odd_curr->next = e_start;
        
        
        return head;
    }
};