#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1877/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int neg=0, pos=0;
        for (int i = 0; i < n-1; i++){
            int x;
            cin >> x;
            if(x<0){
                neg += x;
            }
            else{
                pos += x;
            }
            // cout << x << " ";
        }
        neg *= (-1);
        cout << neg - pos << "\n";
    }

    return 0;
}