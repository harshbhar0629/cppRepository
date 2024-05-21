#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1878/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        bool flag = false;
        
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x==k){
                flag = true;
            }
                
        }

        cout << (flag ? "Yes" : "No") << "\n";
    }

    return 0;
}