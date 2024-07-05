#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9+7;

ll solve(vector<int>& v){
    const int n = v.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++){
        mp[v[i]].push_back(i);
    }

    vector<ll> powerTwo(n + 1, 0);
    powerTwo[0] = 1;
    for (int i = 1; i < n; i++){
        powerTwo[i] = (2 * powerTwo[i - 1]) % mod;
    }

    ll ans = 0;
    for(auto it: mp){
        vector<int> v = it.second;
        ll prev = 0;
        for (int i = 1; i < v.size(); i++){
            ll between = v[i] - v[i - 1] - 1;
            // cout << powerTwo[between] << " ";
            ll curr = (powerTwo[between] + (powerTwo[between + 1] * prev)) % mod;
            ans += curr;
            ans %= mod;
            prev = curr;
        }
        // cout << ans << " \n";
    }

    return ans;
}

// 7
// 1 2 1 3 6 5 3

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << solve(v) << "\n";

    return 0;
}