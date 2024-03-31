#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/redundant-connection/description/

class Solution{

    vector<int>par;
    int find(int x){
        if(par[x] == -1) return x;
        return par[x] = find(par[x]);
    }

    bool _union(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return true;
        par[u] = v;
        return false;
    }

public:
    vector<int> findredundantConnections(vector<vector<int>>& edges){
        int n = edges.size();
        par.resize(n+1, -1);
        vector<int>res;

        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            bool b = _union(u, v);
            if(b){
                res = edges[i];
            }
        }
        return res;
    }
};


int main(){
    

    return 0;
}