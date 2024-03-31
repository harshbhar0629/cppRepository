#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // taking prefix sum
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == k)
            {
                cnt++;
            }
            int val = nums[i] - k;
            // add remaining subarray
            cnt += mp[val];
            mp[nums[i]]++;
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}