#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-linked-list/description/

//   Definition for singly-linked list.
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

    ListNode *f(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *revHead = f(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        // return f(head);
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main()
{

    return 0;
}