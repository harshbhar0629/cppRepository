#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1903/A

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> v(n);
        for (int i = 0; i<n; i++){
            cin >> v[i];
        }

        const auto solve = [&]()
        {
            if(k>1){
                cout << "Yes\n"; // why..? bcoz we can reverse any subarray which length have less than or equal to k so in every case we r able to sort the array in non-decreasing order
            }
            else{
                // when k=1 then array have must to be sorted for sort the array in non-decreasing order
                bool flag = true;
                for (int i = 0; i < n-1; i++){
                    if(v[i] > v[i+1]){
                        flag = false;
                        break;
                    }
                }
                flag ? cout << "Yes\n" : cout << "No\n";
            }
        };
        solve();
    }

    return 0;
}
