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
    ListNode* middleNode(ListNode* head) {
        ListNode* ans=head;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            ans = ans->next;
            temp = temp->next->next;
        }
        return ans;
        
        // int n=0;
        // ListNode* temp = head;
        
        // while(temp!=NULL){
        //     n++;
        //     temp = temp->next;
        // }

        // temp = head;

        // for(int i=1;i<=n/2;i++)  temp = temp->next;
        
        // return temp;
    }
};