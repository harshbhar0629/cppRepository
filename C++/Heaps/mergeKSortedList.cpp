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

    /**
     *  TC = O(n K^2)
     * 1n -|
     *       2n
     * 2n -|
     *       3n
     * 3n  |
     *       4n
     * 4n  |
     *       5n
     * 5n  |
     *       6n
     * 6n  |
     *       7n
     * 7n  |
     *       8n
     * 8n  |
    */

    ListNode* merge(ListNode* tempA, ListNode* tempB) {
        ListNode* ans = new ListNode(10);
        ListNode* tempC = ans;

        while(tempA != NULL and tempB != NULL){

            if(tempA->val <= tempB->val){
                tempC->next = tempA;
                tempC = tempC->next;
                tempA = tempA->next;
            }

            else{
                tempC->next = tempB;
                tempC = tempC->next;
                tempB = tempB->next;
            }
        }

        if(tempA != NULL){
            tempC->next = tempA; 
        }
        else{
            tempC->next = tempB;
        }

        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if( arr.size() == 0) return NULL;

        while(arr.size()>1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());

            // ListNode* b = arr.back();
            // arr.pop_back();

            ListNode* c = merge(arr[0],a);
            arr.erase(arr.begin());
            arr.push_back(c);
        }

        return arr[0];
    }
};

/*************************************************************************************/

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
class cmp{
public:
    bool operator()(const ListNode* l1 , ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    // O(n kLogK)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) continue;
            pq.push(lists[i]);
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(pq.size()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr->next) pq.push(curr->next);
            temp->next = curr;
            temp = temp->next;
        }

        return ans->next;
    }
};