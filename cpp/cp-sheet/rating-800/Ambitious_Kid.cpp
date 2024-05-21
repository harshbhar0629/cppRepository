#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1866/A

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin >> n;
        int mini = 1e9, maxi = -1e9;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x>=0){
                mini = min(mini, x);
            }
            else{
                maxi = max(maxi, x);
            }
        }

        cout << min(maxi * -1, mini) << "\n";
    }

    return 0;
}