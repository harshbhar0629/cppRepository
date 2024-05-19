#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1973/problem/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if ((p1 + p2 + p3) % 2)
        {
            cout << -1;
        }
        else{
            if(p1+p2 < p3){
                cout << p1 + p2;
            }
            else{
                cout << (p1 + p2 + p3) / 2;
            }
        }
        cout << " \n";
    }
    // cout << "\n";

    return 0;
}