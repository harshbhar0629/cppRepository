#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

class Solution
{

    bool f(vector<int> &v)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] >= v[i + 1])
                return false;
        }
        return true;
    }

public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                vector<int> v;
                for (int k = 0; k < n; k++)
                {
                    if (k < i || k > j)
                    {
                        v.push_back(nums[k]);
                    }
                }
                if (v.size() and f(v))
                {
                    cnt++;
                }
            }
        }
        return cnt + 1;
    }
};

int main(){
    

    return 0;
}