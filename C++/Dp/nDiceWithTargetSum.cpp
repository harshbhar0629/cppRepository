// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
#include <iostream>
#include <vector>
using namespace std;

// int f(int n,int k,int target){
//     if(n==0 and target==0) return 1;
//     if(n==0 || target<=0) return 0;
//     int sum=0;
//     for(int i=1; i<=6; i++){
//         sum+=f(n-1,k,target-i);
//     }
//     return sum;
// }

#define ll long long int
#define mod 1000000007
vector<vector<ll>> dp;

ll ftd(int n, int k, int target)
{
    if (n == 0 and target == 0)
        return 1;
    if (n == 0 || target <= 0)
        return 0;
    if (dp[n][target] != -1)
        return dp[n][target];
    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum = ((sum % mod) + (ftd(n - 1, k, target - i) % mod)) % mod;
    }
    return dp[n][target] = sum % mod;
}



ll fbu(int n, int k, int target)
{
    dp.resize(35, vector<ll>(1005, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= target; x++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (x - j < 0)
                    break;
                dp[i][x] += dp[i - 1][x - j];
                dp[i][x] %=mod;
            }
        }
    }
    return dp[n][target];
}


int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int target;
    cin >> target;

    cout<<fbu(n,k,target);

    // dp.resize(35, vector<ll>(1005, -1));
    // cout << ftd(n, k, target);

    // cout<<f(n,k,target);

    return 0;
}