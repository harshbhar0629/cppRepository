// https://leetcode.com/problems/is-graph-bipartite/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    bool bfs(vector<vector<int>>&graph, queue<int>& q, vector<int>&color){
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto neighbour: graph[curr]){
                if(color[neighbour] == -1){
                    color[neighbour] = !color[curr];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                q.push(i);
                color[i] = 0;
                bool b= bfs(graph, q, color);
                if(b == false) return false;
            }
        }
        return true;        
    }
};


int main(){
    

    return 0;
}