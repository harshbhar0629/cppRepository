// https://atcoder.jp/contests/dp/tasks/dp_i
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

vector<vector<double>> dp;
vector<double> v;
double f(int i, int x)
{
    if (x == 0)
        return 1.0;
    if (i == -1)
        return 0.0;
    if (dp[i][x] > -9999.0)
        return dp[i][x];

    return dp[i][x] = f(i - 1, x - 1) * v[i] * 1.0 + f(i - 1, x) * (1.0 - (v[i] * 1.0));
}

// 5
// 0.42 0.01 0.42 0.99 0.42

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // cout<<v[i]<<" ";
    }

    dp.resize(3002, vector<double>(1505, -9999.0));
    cout << fixed << setprecision(9) << f(n - 1, n / 2 + 1);

    return 0;
}