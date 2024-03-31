#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/**
 * we have two string s,t
 * represent s-> all character
 * represent t-> we have to find the occurence of t
 * calculate pow array of each and every ith value
 * calculate prefix hash value of till the ith item
 * for any range of sub-string we will easily get the prefix value in just O(1) 
*/

ll mod = 1e9 + 7;
void computePow(vector<ll>& p){
    ll pow = 31;
    p[0] = 1;

    for (int i = 1; i < p.size(); i++){
        p[i] = (p[i - 1] * pow) % mod;
    }
    return;
}

void computeHash(vector<ll>& h, const string& s, vector<ll>& pow){
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++){
        ll val = s[i] - 'a' + 1;
        h[i] = (h[i-1] + (val * pow[i])%mod)%mod;
    }
    return;
}

ll computeHashVal(const string &t, vector<ll>& pow){
    ll hash_val = t[0] - 'a' + 1;
    for (int i = 1; i < t.size(); i++){
        hash_val = hash_val + (t[i] - 'a' + 1) * pow[i];
        hash_val %= mod;
    }
    return hash_val;
}

//it returns occurence of t in string s
vector<int> rabinKarp(const string& s, const string& t){
    int n = s.size();
    int T = t.size();

    vector<ll> p_pow(n, 0);
    computePow(p_pow);
    ll hash_t = computeHashVal(t, p_pow);

    vector<ll> hash(n , 0);
    computeHash(hash, s, p_pow);

    vector<int> occur;
    // cout << hash_t;
    
    //sliding window
    int start = 0, end = T - 1;
    while(end<n){
        ll hash_s = hash[end];
        if(start>0){
            hash_s = (hash_s - hash[start - 1] + mod)%mod;
        }
        if(hash_s == ((hash_t*p_pow[start])%mod)){
            occur.push_back(start);
        }
        start++, end++;
    }

    return occur;
}


int main(){
    int test;
    cin >> test;

    while(test--)
    {
        string s, t;
        cin >> s >> t;
        vector<int>res = rabinKarp(s, t);
        if(res.size() == 0){
            cout << "Not Found" << endl;
            continue;
        }
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++){
            cout << res[i]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}