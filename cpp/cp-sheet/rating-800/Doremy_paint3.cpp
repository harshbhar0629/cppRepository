#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1890/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        const auto solve = [&]()
        {
            unordered_map<int, int> mp;
            for (int i = 0; i<n; i++){
                mp[a[i]]++;
            }
            if(mp.size()>2){
                return "No";
            }
            if(mp.size() == 1){
                return "Yes";
            }
            for(auto it: mp){
                if(n%2){
                    return (it.second == n / 2 + 1) ? "Yes" : (it.second == n / 2) ? "Yes" : "NO";
                }
                else{
                    return (it.second == n / 2) ? "Yes" : "NO";
                }
            }
        };
        cout << solve()<<"\n";
    }

    return 0;
}