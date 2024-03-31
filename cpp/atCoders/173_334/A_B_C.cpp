#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    vector<vector<int>> arr(3);
    for(auto&v: arr){
        int len;
        cin >> len;
        v.resize(len);
        for(auto& x: v){
            cin >> x;
        }
    }

    unordered_set<ll> st;

    for(auto a: arr[0]){
        for(auto b: arr[1]){
            for(auto c: arr[2]){
                st.insert(a + b + c);
            }
        }
    }

    int q;
    cin >> q;

    while(q--){
        ll x;
        cin >> x;
        if(st.find(x) != st.end()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}