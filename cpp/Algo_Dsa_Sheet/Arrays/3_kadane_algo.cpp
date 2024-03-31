#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main(){
    

    return 0;
}