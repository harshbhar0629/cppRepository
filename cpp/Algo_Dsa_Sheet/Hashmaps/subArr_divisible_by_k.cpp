#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int cnt = 0, sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            cnt += mp[rem];
            mp[rem]++;
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}