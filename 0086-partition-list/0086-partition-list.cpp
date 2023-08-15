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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        
        ListNode* leftptr = left;
        ListNode* rightptr = right;
        
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                leftptr->next = temp;
                leftptr  = leftptr->next;
            }    
            else{
                rightptr->next = temp;
                rightptr = rightptr->next;
            }
            temp = temp->next;
        }
        
        leftptr->next = right->next;
        rightptr->next = NULL;
        return left->next;
    }
};

    