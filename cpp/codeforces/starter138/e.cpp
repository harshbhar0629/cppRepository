#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// https://www.codechef.com/problems/TRIPRI

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll val = sqrt(n) + 1;
        vector<bool> v(val + 1, 1);
        vector<ll> p;
        // sieve code
        v[0] = v[1] = false;
        for (ll i = 2; i * i <= val; i++)
        {
            if (v[i] == 1)
            {
                for (ll j = i * i; j <= val; j += i)
                {
                    v[j] = false;
                }
            }
        }

        for (ll i = 2; i <= val; i++)
        {
            if (v[i])
            {
                p.push_back(i);
            }
        }
        bool ans = false;

        for (ll it : p)
        {
            ll x = n - (it * it) - 4;
            if (x <= 1)
                continue;
            ll a = sqrt(x);
            if (a * a == x and binary_search(p.begin(), p.end(), a) and a != it and a != 2)
            {
                ans = true;
                break;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}