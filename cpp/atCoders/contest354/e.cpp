#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc354/tasks/abc354_e

int n;
vector<int> dp;
vector<vector<int>> v;

bool f(int mask){
    if(dp[mask] != -1){
        return dp[mask];
    }

    bool res = false;
    for (int i = 0; i < n; i++){
        if((mask&(1<<i)) == 0) {
            continue;
        }
        for (int j = i+1; j < n; j++){
            if ((mask & (1 << j)) == 0){
                continue;
            }
            if(v[i][0] == v[j][0] || v[i][1] == v[j][1]){
                if(!f(mask ^ (1<<i) ^ (1<<j))){
                    res = true;
                }
            }
        }
    }
    return dp[mask] = res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n, vector<int>(2));
    for (int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1];
    }

    int val = (1 << (n));
    dp.resize(val, -1);
    int mask = (1 << n) - 1;

    auto res = f(mask) ? "Takahashi " : "Aoki ";
    cout << res;

    return 0;
}