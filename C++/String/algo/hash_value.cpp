#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// rabin karp is based on polynomial hashing we require:
// mod bcoz it may exceeds the range of int ,
// prime no which is greater then character set otherwise collision will occur

ll hashValue(string s)
{
    ll pow = 31;
    ll p = 31;
    ll mod = 1e9 + 7;
    ll ans = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
    {
        ans += ((s[i] - 'a' + 1) * pow) % mod;
        pow = (pow * p) % mod;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << hashValue(s);
    vector<int> vl;

    return 0;
}