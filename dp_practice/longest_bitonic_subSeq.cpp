#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution
{
    vector<int> f(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j] < v[i] and dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }

        return dp;
    }

public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> increasing = f(nums);
        reverse(nums.begin(), nums.end());
        vector<int> decreasing = f(nums);
        reverse(decreasing.begin(), decreasing.end());

        int maxi = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (increasing[i] > 1 and decreasing[i] > 1)
                maxi = max(increasing[i] + decreasing[i] - 1, maxi);
        }

        return maxi;
    }
};

int main(){
    

    return 0;
}