// https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

int solve1(int x, int y, int z, int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int a = 1 + solve1(x, y, z, n - x);
    int b = 1 + solve1(x, y, z, n - y);
    int c = 1 + solve1(x, y, z, n - z);
    return max({a, b, c});
}

vector<int> dp;
int solve2(int x, int y, int z, int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    int a = 1 + solve2(x, y, z, n - x);
    int b = 1 + solve2(x, y, z, n - y);
    int c = 1 + solve2(x, y, z, n - z);
    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solve3(int x, int y, int z, int n)
{
    dp.clear();
    dp.resize(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // int ans = solve1(x,y,z,n);
    // if(ans<0) return 0;
    // else return ans;

    dp.clear();
    dp.resize(n + 1, -1);
    int ans = solve2(x, y, z, n);
    if (ans < 0)
        return 0;
    return ans;

    int ans = solve3(x, y, z, n);
    if (ans < 0)
        return 0;
    return ans;
}

int main()
{

    return 0;
}