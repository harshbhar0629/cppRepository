#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *ans = new ListNode(1);
        ListNode *temp = ans;
        int sum = 0;
        head = head->next;

        while (head)
        {
            sum += head->val;

            if (head->val == 0 and sum)
            {
                temp->next = new ListNode(sum);
                sum = 0;
                temp = temp->next;
            }

            head = head->next;
        }
        return ans->next;
    }
};

int main()
{

    return 0;
}