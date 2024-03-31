#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution
{
public:
    vector<int> findArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            ans[i] = nums[i] ^ nums[i - 1];
        }

        return ans;
    }
};

int main(){
    

    return 0;
}