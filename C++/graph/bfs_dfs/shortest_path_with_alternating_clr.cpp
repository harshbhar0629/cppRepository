#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-path-with-alternating-colors/


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it: redEdges){
            graph[it[0]].push_back({it[1], 0});
        }
        for(auto it: blueEdges){
            graph[it[0]].push_back({it[1], 1});
        }

        queue<vector<int>>q;
        vector<int>dis(n, -1);
        // node dis clr
        q.push({0, 0, -1});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr[0];
            int clr = curr[2];
            if(dis[node]==-1){
                dis[node] = curr[1];
            }

            for(auto &it: graph[node]){
                if(it.first != -1 and (clr==-1 || clr != it.second)){
                    q.push({it.first, curr[1]+1, it.second});
                    it.first = -1;
                }
            }
        }
        return dis;
    }
};

int main(){
    

    return 0;
}