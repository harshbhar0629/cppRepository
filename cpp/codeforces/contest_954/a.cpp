#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1986/problem/A

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        cout << min({abs(x - y) + abs(z - y), abs(y - x) + abs(z - x), abs(x - z) + abs(y - z)}) << " \n";
    }

    return 0;
}