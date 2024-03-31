#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<list<int>>graph;
vector<int> wt;

void edge(int u, int v, bool flag = true){
    graph[u].push_back(v);
    
    graph[v].push_back(u);
    
}

bool f1(vector<bool>& vis, int n, int src){
    if(src==n)
        return vis[src] = true;
    if(vis[src])
        return true;
    vis[src] = true;
    for(auto it: graph[src]){
        if(wt[src] > wt[it]){
            // cout << it << " ";
            bool b = f1(vis, n, it);
            if(b)
                return true;
        }
    }

    vis[src] = false;
    return false;
}



int f(int n){
    vector<bool> vis(n + 1, 0);
    f1(vis, 1, n);

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if(vis[i] == 1){
            cnt++;
            cout << i << " ";
        }
    }
    return vis[1]==1 ? cnt: 0;
}


int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1, list<int>());
    wt.resize(n+1);

    for (int i = 1; i<=n; i++){
        cin >> wt[i];
    }

    while(m--){
        int u, v;
        cin >> u >> v;
        edge(u, v);
    }

    cout << f(n) << endl;
    

    return 0;
}