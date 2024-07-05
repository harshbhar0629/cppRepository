#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

//  Definition for singly-linked list.
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int idx = 2;
        int fIdx = -1, lastIdx = -1;
        int mini = 1e8, maxi = -1, prevVal = head->val;
        head = head->next;

        while (head)
        {
            if (prevVal < head->val and head->next and head->val > head->next->val)
            {
                if (fIdx == -1)
                {
                    fIdx = lastIdx = idx;
                }
                else
                {
                    mini = min(mini, idx - lastIdx);
                    maxi = max(idx - fIdx, maxi);
                }
                lastIdx = idx;
            }
            else if (prevVal > head->val and head->next and head->val < head->next->val)
            {
                if (fIdx == -1)
                {
                    fIdx = lastIdx = idx;
                }
                else
                {
                    mini = min(mini, idx - lastIdx);
                    maxi = max(idx - fIdx, maxi);
                }
                lastIdx = idx;
            }
            idx++;
            prevVal = head->val;
            head = head->next;
        }

        if (mini == 1e8)
        {
            return {-1, -1};
        }

        return {mini, maxi};
    }
};

int main()
{

    return 0;
}