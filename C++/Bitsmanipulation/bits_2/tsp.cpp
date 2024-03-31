#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

class Solution
{
    typedef long long int ll;
    // int dp[21][1048576+1];

    int f(int curr, int mask, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (mask == ((1 << n) - 1))
        {
            return grid[curr][0];
        }
        if (dp[curr][mask] != -1)
        {
            return dp[curr][mask];
        }

        ll ans = INT_MAX;
        for (int neigh = 0; neigh < n; neigh++)
        {
            if ((mask & (1 << neigh)) == 0)
            {
                ans = min(ans, 1ll * grid[curr][neigh] + 1ll * f(neigh, (mask | (1 << neigh)), n, grid, dp));
            }
        }

        return dp[curr][mask] = ans;
    }

public:
    int total_cost(vector<vector<int>> cost)
    {
        // memset(dp, -1, sizeof dp);
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>((1 << n) + 1, -1));
        return f(0, 1, n, cost, dp);
    }
};

int main(){
    

    return 0;
}