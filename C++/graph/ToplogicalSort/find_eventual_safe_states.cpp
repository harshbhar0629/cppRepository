#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //make another graph all out going edge convert to incoming edge
        int n = graph.size();
        vector<list<int>>adj(n, list<int>());
        vector<int>indeg(n,0);

        for(int i=0; i<n; i++){
            for(auto x: graph[i]){
                adj[x].push_back(i);
                indeg[i]++;
            }
        } 

        queue<int>qu;
        vector<bool>vis(n,0);
        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            vis[curr] = true;

            for(auto x: adj[curr]){
                if(--indeg[x]==0){
                    qu.push(x);
                }
            }
        }

        vector<int>res;
        for(int i=0; i<n; i++){
            if(vis[i]==true){
                res.push_back(i);
            }
        }

        return res;
    }
};


class Solution {

    bool dfs(int src, vector<bool>& vis, vector<bool>&inStack, vector<vector<int>>&graph){
        //check src node is visited if yes then don't go in cycle
        if(inStack[src]) return true;

        // check in curr dfs call stck not contain this src then this is already visited from this call then return false
        if(vis[src]) return false;
        
        //mark curr node visited and also mark in stack as well 
        vis[src] = true;
        inStack[src] = true;

        for(auto x: graph[src]){
            if(dfs(x, vis, inStack, graph)){
                return true;
            }
        }

        //after call remove extra node by marking false in stack
        inStack[src] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>res;
        int n = graph.size();
        vector<bool>vis(n,0), inStack(n,0);

        for(int i=0; i<n; i++){
            // if(
                dfs(i, vis, inStack, graph);
            // }
        }

        for(int i=0; i<n; i++){
            if(!inStack[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    

    return 0;
}