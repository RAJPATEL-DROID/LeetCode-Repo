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
};