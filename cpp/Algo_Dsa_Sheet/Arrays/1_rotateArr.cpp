#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return;
        }
        int n = nums.size();
        k %= n;
        for (int i = 0; i < n / 2; i++)
        {
            swap(nums[i], nums[n - 1 - i]);
        }

        for (int i = 0; i < k / 2; i++)
        {
            swap(nums[i], nums[k - 1 - i]);
        }

        int i = k, j = n - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++, j--;
        }

        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    

    return 0;
}