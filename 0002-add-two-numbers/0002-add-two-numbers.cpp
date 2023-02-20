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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* f = l1;
        ListNode* s = l2;
        
        int carry =0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while( f != NULL || s != NULL || carry){
            int sum =0;
            
            if(f!= NULL){
                sum += f->val;
                f = f->next;
            }
            
            if(s != NULL){
                sum += s->val;
                s = s->next;
            }
            
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};