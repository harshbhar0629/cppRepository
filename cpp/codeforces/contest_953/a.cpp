#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1978/problem/A

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int mx = *max_element(a.begin(), a.end() - 1);
        cout << mx + a.back() << "\n";
    }

    return 0;
}