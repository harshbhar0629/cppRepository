#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc179/tasks/abc179_c

int main(){
    int n;
    cin >> n;

    int total = 0;
    for(int i=1; i<n; i++){
        for (int j = 1; j * i < n; j++){
            total++;
        }
    }

    cout << total << "\n";

    return 0;
}