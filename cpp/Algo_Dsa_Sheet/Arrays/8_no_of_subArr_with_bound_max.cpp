#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();
        int cnt = 0;
        int ans = 0;
        int l = 0, r = 0;

        while (r < n)
        {
            if (right < nums[r])
            {
                l = r + 1;
            }
            if (left <= nums[r] and nums[r] <= right)
            {
                cnt = (r - l + 1);
                ans += cnt;
            }
            else if (nums[r] < left)
            {
                ans += cnt;
            }
            else
            {
                cnt = 0;
            }
            r++;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}