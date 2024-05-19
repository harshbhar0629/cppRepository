#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc354/tasks/abc354_a
// https://discuss.codechef.com/t/amr16j-editorial/16392

#define ll long long int

int main(){
    ll h;
    cin >> h;
    ll val = 1;
    int cnt = 0;
    while(val-1 <= h){
        cnt++;
        val = val * 2;
        
    }
    cout << cnt << "\n";

    return 0;
}