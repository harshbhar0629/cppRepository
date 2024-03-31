#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

class Solution
{

    // TC: without dp -> O((n*2^n)/k)
    // with dp = (n^3/k)
    int dp[35][35];
    int f(int start, int end, const int k, const vector<int> &stones, const vector<int> &pre)
    {
        if (end - start < k - 1)
        {
            return 0;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        int ans = 1e9;
        for (int i = start; i < end; i += (k - 1))
        {
            int left = f(start, i, k, stones, pre);
            int right = f(i + 1, end, k, stones, pre);
            ans = min(ans, left + right);
        }

        //valid merging
        if ((end - start) % (k - 1) == 0)
        {
            // add cost of merging
            ans += pre[end + 1] - pre[start];
        }

        return dp[start][end] = ans;
    }

public:
    int mergeStones(vector<int> &stones, int k)
    {

        int n = stones.size();
        if ((n - 1) % (k - 1))
        {
            return -1;
        }

        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + stones[i];
        }

        memset(dp, -1, sizeof dp);
        return f(0, n - 1, k, stones, pre);
    }
};

int main(){
    

    return 0;
}