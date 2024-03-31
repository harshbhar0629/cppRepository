#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_g

vector<int>graph[100005];
int dp[100005];

int longestPath(int src){
    if(dp[src] != -1){
        return dp[src];
    }
    bool leaf = 1;
    int ans = 0;

    for(auto child: graph[src]){
        leaf = 0;
        ans = max(ans, longestPath(child));
    }

    return dp[src] = (leaf == 1) ? 0 : 1 + ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 1; i<=n; i++){
        ans = max(longestPath(i), ans);
    }

    cout << ans << "\n";

    return 0;
}