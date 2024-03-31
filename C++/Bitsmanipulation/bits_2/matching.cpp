#include<bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_o

const int mod = 1e9 + 7;
int dp[22][1 << 22];

int f(int i, int mask, vector<vector<int>>& c, const int n){
    if(i==n+1){
        if(mask==0){
            return 1;
        }
        return 0;
    }
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }

    int ans = 0;
    for (int w = 1; w <= n; w++){
        bool available = (((1 << (w - 1)) & mask) == 0) ? 0 : 1;
        if(available and c[i][w]){
            ans = ((ans % mod) + f(i + 1, mask ^ (1 << (w - 1)), c, n)%mod)%mod;
        }
    }

    return dp[i][mask] = ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> c(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << f(1, (1 << n) - 1, c, n);
    return 0;
}