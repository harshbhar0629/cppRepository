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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempA=list1;
        ListNode* tempB=list1;

        while(--a){
            tempA =tempA->next;
        }

        while(b--){
            tempB = tempB->next;
        }

        tempA->next = list2;
        tempA= tempA->next;

        while(tempA->next!=NULL){
            tempA = tempA->next;
        }

        tempA->next = tempB->next;
        return list1;;

    }
};