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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        if(head->next == NULL || k ==0)return head;
        ListNode* last = head;
        int count =1;
        while(last->next != NULL){
            count++;
            last = last->next;
        }
        k = k%count;
        while(k--){
            last  = head;
            while(last->next->next != NULL){
                last = last->next;
            }   
            ListNode* temp = last->next;
            temp->next = head;
            head = temp;
            last->next = NULL;
        }
        return head;
    }
};