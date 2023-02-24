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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        
//         // Method 1 -> O(1) space complexity but more iterations
//         ListNode* dummy = new ListNode();
//         ListNode* last = dummy;
        
//         while(list1 != NULL && list2 != NULL){
//                 if(list1->val >= list2->val){
//                     last->next = list2;
//                     last = last->next;
//                     list2 = list2->next;
//                 }else{
//                     last->next = list1;
//                     last = last->next;
//                     list1 = list1->next;
//                 }
//         }
        
//         while(list1 !=NULL){
//             last->next = list1;
//             list1 = list1->next;
//             last = last->next;
//         }
//         while(list2 != NULL){
//             last->next = list2;
//             last = last->next;
//             list2 = list2->next;
//         }
        
//         return dummy->next;
        
        // Method 2 -> O(1) Space Complexity but lesser iteration
        if(list1->val > list2->val){
            swap(list1,list2);
        }
        
        ListNode* res = list1;
        
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next =list2;
            // swap
            swap(list1,list2);
        }
        
        return res;
            
    }
};