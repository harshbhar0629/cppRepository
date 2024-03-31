#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n+1, -1);
        // for(int i=0; i<n+1; i++) parent[i] = i;
        rank.resize(n+1, 0);
    }
    int find(int x){
        if(parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    void _union(int u, int v) {
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(rank[u] >= rank[v]){
            rank[u]++;
            parent[v] = u;
        }
        else{
            rank[v]++;
            parent[u] = v;    
        }
        return;
    }
};


class Solution {
    // vector<bool>vis;
    // void dfs(int i, vector<vector<int>>& st){
    //     vis[i] = true;
    //     for(int idx=0; idx<st.size(); idx++){
    //         if(!vis[idx] and (st[idx][0] == st[i][0] || st[idx][1] == st[i][1])){
    //             dfs(idx, st);
    //         }
    //     }
    // }

public:
    int removeStones(vector<vector<int>>& stones) {
        // int n = stones.size();
        // vis.resize(n, 0);
        // int group = 0;
        // for(int i=0; i<n; i++){
        //     if(!vis[i]){
        //         dfs(i, stones);
        //         group++;
        //     }
        // }
        // return n-group; 

        /*DSU*/
        int n = stones.size();
        int maxRow=0, maxCol=0;

        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int size = maxRow + maxCol;
        DSU ds(size+1); 
        unordered_map<int,int>mp;

        for(auto it: stones){
            int r = it[0];
            int c = it[1] + maxRow+1;
            ds._union(r, c);
            mp[r] = 1;
            mp[c] = 1;
        }

    //     for(int i=0; i<size+1; i++){
    //         cout<<i<<" -> "<<ds.parent[i]<<endl;
    //     }
    // cout<<endl;
        int cnt = 0;
        for(auto it: mp){
            // cout<<it.first<<" ";
            int x = ds.find(it.first);
            if(x==it.first) cnt++;
        }

        return n - cnt;
    }
};


int main(){
    

    return 0;
}