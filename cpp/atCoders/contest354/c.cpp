#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc354/tasks/abc354_c

int main(){
    
    // Choose two cards x and y such that Ax > Ay and Cx<Cy. Discard card y A=>strength and c=>cost
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));

    for (int i = 0; i < n; i++){ 
        cin >> v[i][0] >> v[i][1]; // oth item denotes strength of ith card and 1th item card denotes the cost of ith card
        v[i][2] = i;
    }

    sort(v.begin(), v.end(), [&](auto &a, auto &b)
         { return a[0] > b[0]; });
    
    int prevMn = 1e9 + 7;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if(v[i][1] > prevMn){
            continue;
        }
        prevMn = v[i][1];
        ans.push_back(v[i][2]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto a: ans){
        cout << a+1 << " ";
    }

    cout << endl;

    return 0;
}