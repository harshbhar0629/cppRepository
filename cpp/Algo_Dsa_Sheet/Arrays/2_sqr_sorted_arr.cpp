#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1214103519/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int idx = n;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                idx = i;
                break;
            }
        }

        int i = idx - 1;
        vector<int> ans;
        while (idx < n and i >= 0)
        {
            int pos = nums[idx] * nums[idx];
            int neg = nums[i] * nums[i];
            if (neg <= pos)
            {
                ans.push_back(neg);
                i--;
            }
            else
            {
                ans.push_back(pos);
                idx++;
            }
        }
        while (i >= 0)
        {
            int neg = nums[i] * nums[i];
            ans.push_back(neg);
            i--;
        }
        while (idx < n)
        {
            int pos = nums[idx] * nums[idx];
            ans.push_back(pos);
            idx++;
        }
        return ans;
    }
};

int main(){
    

    return 0;
}