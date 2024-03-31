#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-subarray/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxPdt = nums[0];
        int negPdt = nums[0];
        int pdt = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
            {
                swap(negPdt, pdt);
            }
            pdt = max(nums[i], pdt * nums[i]);
            negPdt = min(nums[i], negPdt * nums[i]);
            maxPdt = max(maxPdt, pdt);
        }

        return maxPdt;
    }
};

int main(){
    

    return 0;
}