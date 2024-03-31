// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int dp[2005][2005][8];
int f(vector<int> &a, vector<int> &b, int i, int j, int k)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    int res = 0;
    // if both are equal
    if (a[i] == b[j])
    {
        res = max(res, 1 + f(a, b, i + 1, j + 1, k));
    }
    // if k exist then we have choice to change LCS order
    else
    {
        if (k > 0)
        {
            res = max(res, 1 + f(a, b, i + 1, j + 1, k - 1));
        }
        res = max({f(a, b, i + 1, j, k), f(a, b, i, j + 1, k), res});
    }
    return dp[i][j][k] = res;
}

int main()
{

    int k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    memset(dp, -1, sizeof dp);
    cout << f(a, b, 0, 0, k) << "\n";
}