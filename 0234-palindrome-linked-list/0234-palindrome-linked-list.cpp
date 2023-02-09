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
    ListNode* reverse(ListNode* node){
        ListNode* nxt= NULL;
        ListNode* prev = NULL;
        
        while(node!=NULL){
            nxt = node->next;
            node->next= prev;
            prev = node;
            node =nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)break;
        }
        
        slow = reverse(slow);
        ListNode* dummy = head;
        
        while(slow != NULL){
            if(slow->val != dummy->val)return false;
            slow = slow->next;
            dummy = dummy->next;
        }
        return true;
    }
};