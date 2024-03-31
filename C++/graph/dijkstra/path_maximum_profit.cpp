#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-with-maximum-probability/



using pid = pair<int,double>;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<list<pid>>graph(n);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        queue<pid>qu;
        vector<double>dis(n, 0.0);
        qu.push({start_node, 1.0});
        dis[start_node] = 1.0;

        // while(!qu.empty()){
        //     auto [node, wt] = qu.front();
        //     qu.pop();
        //     for(auto& [curr_node, curr_wt]: graph[node]){
        //         if(dis[curr_node] < wt * curr_wt){
        //             dis[curr_node] = wt*curr_wt;
        //             qu.push({curr_node, dis[curr_node]});
        //         }
        //     }
        // }
        return dis[end_node];
    }
};


int main(){
    

    return 0;
}