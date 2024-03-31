#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/1124705542/

class Solution {
    vector<int>par;
    int find(int x){
        if(par[x]==-1) return x;
        return par[x] = find(par[x]);
    }

    void _union(int s, int d){
        s = find(s);
        d = find(d);
        if(s==d) return;
        par[s] = d;
        // par[d] = d;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        par.resize(n,-1);
        for(auto& x: edges){
            _union(x[0], x[1]);
        }
        
        src = find(src);
        dest = find(dest);
        return src == dest;
        // if(find(par[src]) == find(par[dest])) return true;
        // return false;
    }
};


int main(){
    

    return 0;
}