#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n);
        for (int i = 0; i<n; i++){
            cin >> a[i];
        }

        int ans=0;
        ll prefixSum = 0, prefixMax = -1;
        for (int i = 0; i<n; i++){
            prefixMax = max(prefixMax, a[i]);
            prefixSum += a[i];
            if(2*prefixMax == prefixSum)
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}