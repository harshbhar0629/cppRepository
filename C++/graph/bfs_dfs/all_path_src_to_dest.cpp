#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {

    vector<vector<int>>res;
    int size;

    void dfs(int s, vector<vector<int>>& graph, vector<int> v){
        v.push_back(s);
        int n = graph[s].size();
        if(s==size-1) {
            res.push_back(v);
            return;
        }
        else for(auto it: graph[s]){
                dfs(it, graph, v);
            }
        v.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        size = graph.size();
        dfs(0,graph, {});
        return res;
    }
};

int main(){
    

    return 0;
}