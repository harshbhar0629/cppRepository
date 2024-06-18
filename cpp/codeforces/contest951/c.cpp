#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int LCM(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;

        vector<ll> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        ll x = v[0];
        for (int i = 1; i < n; i++){
            x = LCM(x, v[i]);
        }

        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            a[i] = x / v[i];
        }

        if(accumulate(a.begin(), a.end(), 0ll) >= x){
            cout << "-1" << "\n";
            continue;
        }

        for(auto it: a){
            cout << it << " ";
        }
        cout<<"\n";
    }
    

    return 0;
}