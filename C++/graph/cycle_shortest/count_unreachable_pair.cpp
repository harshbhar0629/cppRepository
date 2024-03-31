// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int count ;
    void dfs(int idx,vector<int> adj[], vector<bool>& visited){
        visited[idx] = true;
        for(auto it: adj[idx]){
            if(!visited[it]){
                count++;
                dfs(it, adj, visited);
            }
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // vector<int>arr;
        vector<bool>visited(n,0);
        vector<int>adj[n];
        long long int ans = 0,taken =0;

        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                count = 1;
                dfs(i, adj, visited);
                // arr.push_back(count);
                taken+=count;
                ans = ans + (n-taken)*count;
            }
        }
        
        return ans;
    }
};


class Solution {

    vector<int>par, size;
    int find(int x){
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }

    void _union(int a, int b){
        a = find(a);
        b = find(b);
    
        if(size[a]<=size[b]){
            par[a] = b;
            size[b]+=size[a];
            size[a]=0;
        }
        else{
            par[b] = a;
            size[a]+=size[b];
            size[b]=0;
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        par.resize(n);
        size.resize(n,1);
        iota(par.begin(), par.end(), 0);
    
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            _union(u,v);
        }
        long long int ans = 0, taken=0;

        for(int i=0; i<n; i++){
            if(size[i]!=0){
                taken+=size[i];
                ans+= (n-taken)*size[i];
            }
        }
        return ans;
    }
};


int main(){
    

    return 0;
}