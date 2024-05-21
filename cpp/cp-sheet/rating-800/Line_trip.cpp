#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1901/A

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int dis;
        cin >> dis;

        vector<int> a(n);
        for (int i = 0; i<n; i++){
            cin >> a[i];
        }

        const auto solve = [&]()
        {
            // we have to calc. min possible fuel required to travel from 0 to dis and dis to 0.
            int maxFuelReq = 0;
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                maxFuelReq = max(maxFuelReq, a[i] - x);
                x = a[i];
            }
            maxFuelReq = max(maxFuelReq, 2 * (dis - x));
            cout << maxFuelReq << "\n";
        };
        solve();
    }
    

    return 0;
}