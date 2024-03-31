#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_u

// precompute all subset sum
// f-> it returns max achievable score of grouping n-rabbits
// calculate function it generate all possible subset and after return ans

/*********************** Code ************************/

#define ll long long int
vector<ll> sums(1 << 16+1, 0);
vector<ll> dp(1 << 16+1, INT_MAX);

ll calc(vector<vector<ll>> &compat, int mask)
{
    ll ans = 0;
    for (int i = 0; i <= 16; i++){
        for (int j = i + 1; j <= 16; j++){
            if (((mask & (1 << i)) != 0) and ((mask & (1 << j)) != 0)){
                ans += compat[i][j];
            }
        }
    }
    return ans;
}

void precompute(vector<vector<ll>> &compat, int n){
    for (int i = 1; i <= ((1 << n) - 1); i++){
        sums[i] = calc(compat, i);
    }
}

ll f(vector<vector<ll>> &compat, int n, int mask)
{
    if (mask == 0){
        return 0;
    }
    if (dp[mask] != INT_MAX){
        return dp[mask];
    }

    ll ans = 0;
    for (int j = mask; j != 0; j = ((j - 1) & mask)){
        ans = max(ans, sums[j] + f(compat, n, mask ^ j));
    }
    return dp[mask] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> compat(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> compat[i][j];
        }
    }

    precompute(compat, n);
    cout << f(compat, n, ((1 << n) - 1));

    return 0;
}