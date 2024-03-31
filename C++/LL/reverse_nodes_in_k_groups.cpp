#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  * Definition for singly-linked list.

int length(ListNode *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    int len = length(head);
    if (!head or len < k)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = dummy;
    ListNode *prev = dummy;
    ListNode *nex = dummy;
    while (len >= k)
    {
        curr = prev->next;
        nex = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        len -= k;
    }
    return dummy->next;
}

class Solution
{

    int length(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = length(head);
        // base case for empty and having length less than k of linked list
        if (len < k || head == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *after;
        ListNode *curr = head;
        int l = 0;

        // iterate k length linked list and reverse
        while (l < k)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
            l++;
        }

        // make recursive call for all remaining nodes
        if (after != NULL)
            head->next = reverseKGroup(after, k);

        // return the head of modified linked list
        return prev;
    }
};

int main()
{

    return 0;
}