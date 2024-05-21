#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1899/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%3){
            cout << "First";
        }
        else{
            cout << "Second";
        }
        cout << "\n";
    }

    return 0;
}