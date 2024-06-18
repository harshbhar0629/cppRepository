#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        vector<ll> d;
        for (ll i = 1; i <= sqrt(k); i++){
            if(k%i == 0){
                d.push_back(i);
                if(i*i != k){
                    d.push_back(k / i);
                }
            }
        }
        ll maxi = *max_element(d.begin(), d.end());

        for (ll i = 1; i <= min(x, maxi); i++){
            for (ll j = 1; j < min(y, maxi); j++){
                for (ll m = 1; min(z, maxi); m++){
                    
                }
            }
            
        }
    }

    return 0;
}