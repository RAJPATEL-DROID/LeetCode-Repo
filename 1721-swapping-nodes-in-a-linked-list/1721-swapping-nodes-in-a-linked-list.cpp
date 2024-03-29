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
    ListNode* swapNodes(ListNode* head, int k) {
//         ListNode* slow =head;
        
//         int count =0,value = 0;
//         while(slow != NULL){
//             if(count == k-1)value = slow->val;
//             slow = slow->next;
//             count++;
//         }
        
//         // cout<<count<<" "<<value<<" ";
//         slow = head;
//         int i=1;
//         while(i != count+1 - k){
//             slow = slow->next;
//             i++;
//         }
//         i = slow->val;
//         // cout<<i<<"\n";
//         slow->val = value;
//         slow = head;
//         count =1;
//         while(count != k){
//             slow = slow->next;
//             count++;
//         }
//         slow->val = i;
//         return head;
        
         ListNode *n1 = nullptr, *n2 = nullptr;
        for (auto p = head; p != nullptr; p = p->next) {
            n2 = n2 == nullptr ? nullptr : n2->next;
            if (--k == 0) {
                n1 = p;
                n2 = head;
            }
        }
        
        swap(n1->val,n2->val);
        return head;
    }
};