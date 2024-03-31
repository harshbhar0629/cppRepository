#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/271/D
#define ll long long int
const ll mod = 1e9 + 7;

int solve(string &s, string &t, int k)
{
    int n = s.size();
    // vector<ll> p1(n, 0), p2(n, 0);

    // p1[0] = p2[0] = 1;
    // ll p11 = 31;
    // ll p22 = 29;

    // for (int i = 1; i < n; i++)
    // {
    //     p1[i] = (p1[i - 1] * p11) % mod;
    //     p2[i] = (p2[i - 1] * p22) % mod;
    // }
    set<pair<ll, ll>> st;

    for (int i = 0; i < n; i++)
    {
        ll bc = 0;
        ll p1 = 31, p2 = 29;
        ll p11 = 31, p22 = 29;
        ll hash1 = 0, hash2 = 0;

        for (int j = i; j < n; j++)
        {
            bc += (t[s[j] - 'a'] == '0') ? 1 : 0;
            // check good or not if not then exist from loop
            if (bc > k)
            {
                break;
            }

            // calculate hash of substring [i..j]
            hash1 = (hash1 + (s[j] - 'a' + 1) * p1) % mod;
            hash2 = (hash2 + (s[j] - 'a' + 1) * p2) % mod;

            // it store always unique hashes
            st.insert({hash1, hash2});

            p1 = (p1 * p11) % mod;
            p2 = (p22 * p2) % mod;
        }
    }

    return st.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int k;
    cin >> k;

    cout << solve(s, t, k) << "\n";

    return 0;
}