#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/contest/biweekly-contest-126/problems/find-the-sum-of-the-power-of-all-subsequences/

#define ll long long int
int dp[105][105][105];
vector<int> nums;
int k;
const int mod = 1e9 + 7;

ll p(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    ll ans = p(x, n / 2) % mod;
    if (n % 2 == 0)
    {
        return (ans * ans) % mod;
    }
    else
    {
        return (ans * ans * x) % mod;
    }
}

ll f(int i, int sum, int skip)
{
    if (i == nums.size())
    {
        if (sum == k)
        {
            return p(2, skip) % mod;
        }
        return 0;
    }
    if (dp[i][sum][skip] != -1)
    {
        return dp[i][sum][skip];
    }

    ll ans = f(i + 1, sum, skip + 1) % mod;

    if (sum + nums[i] <= k)
    {
        ans = (ans + f(i + 1, sum + nums[i], skip) % mod) % mod;
    }

    return dp[i][sum][skip] = ans%mod;
}

ll sumOfPower(vector<int> &num, int K)
{
    nums = num;
    k = K;
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;

    cout << sumOfPower(nums, k) << "\n";

    return 0;
}