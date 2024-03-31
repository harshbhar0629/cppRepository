/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
  ListNode* slow=head;
        ListNode* fast = head;

        for(int i=1;i<=k;i++) fast= fast->next;

        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next=head;
        head= slow->next;
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;

        ListNode* temp = head;
        int len=0;

        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        k = k%len;
        temp = head;

        for(int i=1 ;i<len-k;i++){
            temp = temp->next;
        }

        ListNode* t= temp;

        while(temp!=NULL and temp->next!= NULL){
            temp = temp->next;
        }

        temp->next = head;
        head = t->next;
        t->next = NULL;

        return head;
    }
};