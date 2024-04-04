#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/linked-list-cycle-ii/description/
// https://leetcode.com/problems/linked-list-cycle/description/

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};


class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle)
        {
            ListNode *temp = head;
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }

        return NULL;
    }
};

int main()
{

    return 0;
}