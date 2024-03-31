#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

using pi = pair<int,int>;
class Solution {

    int count =0 ;
    void dfs(int src, int parent, vector<list<pi>>& g, vector<bool>& vis){
        if(vis[src]) return;
        vis[src] = true;
        for(auto [child, sign]: g[src]){
            if(child!=parent){
                count+= sign;
                dfs(child, src, g, vis);
            }
        }
    }

    void bfs(int src, int n, vector<list<pi>>& g,  vector<bool>& vis){
       
        queue<int>q;
        q.push(src);
        // vis[src] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            for(auto [node, sign]: g[curr]){
                if(!vis[node]){
                    q.push(node);
                    count+=sign;
                }
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<list<pi>>g(n);
        for(auto connection: connections){
            g[connection[0]].push_back({connection[1], 1});
            g[connection[1]].push_back({connection[0], 0});
        }
        vector<bool> vis(n, false);
        dfs(0, -1, g, vis);
        // bfs(0, n, g, vis);
        return count;
    }
};


int main(){
    

    return 0;
}