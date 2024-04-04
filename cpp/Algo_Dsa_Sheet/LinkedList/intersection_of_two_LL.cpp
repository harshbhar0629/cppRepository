#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

    int findLen(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int len1 = findLen(tempA);
        int len2 = findLen(tempB);

        tempA = headA;
        tempB = headB;
        if (len1 > len2)
        {
            for (int i = 1; i <= len1 - len2; i++)
            {
                tempA = tempA->next;
            }
        }
        else
        {
            for (int i = 1; i <= len2 - len1; i++)
            {
                tempB = tempB->next;
            }
        }

        while (tempA and tempB)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};

int main()
{

    return 0;
}