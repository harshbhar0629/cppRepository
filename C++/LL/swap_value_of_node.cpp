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
        ListNode* tempA=head;
        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=1;i<k;i++){
            tempA = tempA->next;
            fast= fast->next;
        }
        
        fast= fast->next;

        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        int x = slow->val;
        slow->val=tempA->val;
        tempA->val = x;
       
        return head;

    }
};