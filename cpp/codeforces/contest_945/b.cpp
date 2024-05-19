#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1973/problem/B

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto solve = [&]()
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 1;
        for (int i = 0; i < 25; i++)
        {
            vector<int> occur;
            for (int j = 0; j < n; j++)
            {
                int bit = ((a[j] & (1 << i)) >= 1) ? 1 : 0;
                if (bit)
                {
                    occur.push_back(j);
                }
            }

            int last = -1, maxi = 0;
            for (auto it : occur)
            {
                maxi = max(maxi, it - last);
                last = it;
            }
            maxi = max(maxi, n - last);
            if (last != -1)
            {
                ans = max(ans, maxi);
            }
        }
        cout << ans << "\n";
    };

    int t;
    cin >> t;
    while(t--){
        
        solve();
    }

    return 0;
}