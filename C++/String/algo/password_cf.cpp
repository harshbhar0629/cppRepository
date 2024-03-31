#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/127/problem/D

#define ll long long int
const int mod = 1e9 + 7;

void computePow(vector<ll>& p){
    ll pow = 31;
    p[0] = 1;
    for (int i = 1; i < p.size(); i++){
        p[i] = (p[i - 1] * pow) % mod;
    }
    return;
}

void computeHash(vector<ll> &hash, vector<ll>&p, const string &s){
    int n = hash.size();
    hash[0] = s[0] - 'a'+1;

    for (int i = 1; i<n; i++){
        hash[i] = (hash[i - 1] + ((s[i] - 'a' + 1) * p[i]) % mod) % mod;
    }
}

ll hashVal(vector<ll> &hash, int l, int r){
    ll ans = hash[r];
    if(l>0){
        ans = (ans - hash[l - 1] + mod) % mod;
    }
    return ans;
}

void solve(string &s)
{
    int n = s.size();
    vector<ll> p(n, 0);
    computePow(p);

    vector<ll> hash(n, 0);
    computeHash(hash, p, s);

    int ans = 0;
    for (int i = 0; i<n-1; i++){
        ll pre = (hash[i]);
        ll suff = hashVal(hash, n - 1 - i, n - 1);
        if (suff == (pre * p[n - 1 - i])%mod)
        {
            int j = 1, k = i + 1;
            while(k<n-1){
                ll curr_hash = hashVal(hash, j, k);
                if(curr_hash == (pre*p[j])%mod){
                    ans = i + 1;
                    break;
                }
                j++, k++;
            }
        }
    }

    if(ans == 0){
        cout << "Just a legend\n";
    }
    else{
        cout << s.substr(0, ans)<<"\n";
    }
}

int main(){
    string s;
    cin>>s;

    solve(s);

    return 0;
}