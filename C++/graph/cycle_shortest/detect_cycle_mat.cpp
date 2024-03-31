#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>>vis;
    int n , m;
    bool b=false;
    void dfs(vector<vector<char>>& grid,int r,int c,int pr=-1,int pc=-1){
        vis[r][c] = true;
        for(int d=0; d<4; d++){
            int i = r + dir[d].first;
            int j = c + dir[d].second;
            if(i==pr and j==pc or i<0 or j<0 or i>=n or j>=m ) continue;
            if(grid[r][c]==grid[i][j]){
                if(vis[i][j]) {
                    b = true;
                    return;
                }
                dfs(grid, i, j, r, c);
            } 
        }
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();
        vis.resize(n,vector<bool>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    dfs(grid, i, j);
                    if(b) return true;
                }
            }
        }
        return false;
    }
};


int main(){
    

    return 0;
}