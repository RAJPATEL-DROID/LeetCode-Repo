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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode dummy(0);  // this will get us memory on stack so no worry about memory Leak
//         dummy.next = head;
        
//         ListNode* prev = &dummy;
//         ListNode* curr = NULL;
//         for(int i=0; i < left -1;i++){
//             prev = prev->next;
//         }
//         curr= prev->next;
        
//         for(int i=0; i < right-left;i++){
//             ListNode* frwd = curr->next;
//             curr->next  = frwd->next;
//             frwd->next = prev->next;
//             prev->next = frwd;
//         }
        
//         return dummy.next;
        
        ListNode* dummy = new ListNode(NULL);
        ListNode* prev = dummy;
        ListNode* curr = NULL;
        dummy->next = head;
        for(int i=0;i < left-1;i++){
            prev = prev->next;
        }
        curr = prev->next;
        
        for(int i=0;i <right-left; i++){
            ListNode* frwd = curr->next;
            curr->next = frwd->next;
            frwd->next = prev->next;
            prev->next = frwd;
        }
        
        return dummy->next;
    }
};