#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-height-trees/
vector<list<int>> graph;
int bfs(int s){
    queue<int>q;
    q.push(s);
    int count=0;
    vector<bool>vis(100000,0);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            for(auto &x: graph[curr]){
                if(!vis[x]) q.push(x);
            }
        }
        count++;
    }
    return count;
}
vector<int> f(int n, vector<vector<int>>& edges){
    vector<int> dis(n,0);
    graph.resize(n, list<int>());
    for(auto& edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        dis[i] = bfs(i);
        mini = min(mini, dis[i]);
    }
    vector<int>res;
    for(int i=0; i<n; i++){
        if(dis[i]==mini) res.push_back(i);
    }
    return res;
}


class Solution {
    vector<list<int>>graph;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        graph.resize(n, list<int>());
        vector<int>indeg(n,0);
        vector<int>res;

        for(auto& v: edges){
            int x = v[0], y = v[1];
            indeg[x]++;
            indeg[y]++;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        queue<int>qu;

        for(int i=0; i<n; i++){
            if(indeg[i]==1){
                indeg[i]--;
                qu.push(i);
            }
        }

        while(!qu.empty()){
            res.clear();
            int sz = qu.size();
            for(int i=0; i<sz; i++){
                int curr = qu.front();
                res.push_back(curr);
                qu.pop();
                for(auto& x: graph[curr]){
                    indeg[x]-- ;
                    if(indeg[x] == 1) {
                        indeg[x]--;
                        qu.push(x);
                    }
                }
            }
        }
        if(n==1) res.push_back(0);
        return res;

        
    }
};

   
int main(){
    

    return 0;
}