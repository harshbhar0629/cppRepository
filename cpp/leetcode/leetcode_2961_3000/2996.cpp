#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {

        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                sum += nums[i];
            }
            else
                break;
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (int i = sum; i <= 50 * 50; i++)
        {
            if (mp.find(i) == mp.end())
                return i;
        }
        return 2501;
    }
};

int main(){
    

    return 0;
}