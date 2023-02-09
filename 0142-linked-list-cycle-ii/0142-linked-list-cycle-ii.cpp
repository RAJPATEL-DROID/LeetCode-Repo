/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Using Hashmap : O(N) Space Complexity
//         unordered_map<ListNode*,int> m;
//          while(head != NULL){
//              m[head]++;
//              if(m[head] >1){
//                  return head;
//              }
//              head = head->next;
//          }
//          return NULL;
        
        // Using O(1) Space 
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            
            // Intution is IMP understand it from NOTES
            if(slow==fast){
                while(slow!=entry){
                    slow = slow->next;entry = entry->next;
                }    
                return entry;
            }
        }
        return NULL;
    }
};