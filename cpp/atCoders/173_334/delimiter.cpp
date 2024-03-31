#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int x;
    cin >> x;
    v.push_back(x);
    while(x!=0){
        cin>>x;
        v.push_back(x);
    }

    for (int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << "\n";
    }

    return 0;
}