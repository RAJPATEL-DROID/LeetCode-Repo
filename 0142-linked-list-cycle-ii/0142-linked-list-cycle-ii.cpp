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
        // Using Hashmap : O(N) Space memory
        unordered_map<ListNode*,int> m;
         while(head != NULL){
             m[head]++;
             if(m[head] >1){
                 return head;
             }
             head = head->next;
         }
         return NULL;
    }
};