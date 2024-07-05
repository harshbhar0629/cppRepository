#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1986/problem/C

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        string a, b;
        cin >> a;
        for (int i = 0; i < m; i++){
            cin >> v[i];
        }
        cin >> b;
        set<int> st(v.begin(), v.end());
        sort(b.begin(), b.end());

        int j = 0;
        for(auto it: st){
            a[it - 1] = b[j];
            j++;
        }

        cout << a << "\n";
    }

    return 0;
}