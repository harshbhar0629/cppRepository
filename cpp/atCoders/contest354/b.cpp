#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc354/tasks/abc354_b
#define ll long long int

int main(){
    int n;
    cin >> n;
    vector<string> v(n);

    ll freq = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        int x;
        cin >> x;
        freq += x;
    }

    sort(v.begin(), v.end());
    cout << v[freq % n] << "\n";

    return 0;
}