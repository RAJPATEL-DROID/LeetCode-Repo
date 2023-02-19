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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* tempNode = new ListNode();
        ListNode* curr = tempNode;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next;
               curr = curr->next; 
            }else if(head1->val > head2->val){
                curr->next = head2;
                head2 = head2->next;
               curr = curr->next;
            } 
        }
        while(head1 != NULL){
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        }
        while(head2 != NULL){
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
       return tempNode->next; 
    }
    
    ListNode* midEle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head){
        if(head->next == NULL)return head;
        ListNode* mid = midEle(head);
        ListNode* rightList = mid->next;  // Splitting the List in 2
        
        mid->next = NULL;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightList);
        
        ListNode* new_head = merge(left,right);
        
        return new_head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL )return NULL;
        ListNode* start = mergeSort(head);
        return start;
    }
};