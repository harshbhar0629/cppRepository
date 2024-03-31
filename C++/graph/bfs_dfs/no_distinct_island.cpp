// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& grid, vector<pair<int,int>>& v, int i, int j, int sr,int sc){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;
    v.push_back({i-sr,j-sc});
    grid[i][j] = 0;

    dfs(grid, v, i+1, j, sr, sc);
    dfs(grid, v, i-1, j, sr, sc);
    dfs(grid, v, i, j+1, sr, sc);
    dfs(grid, v, i, j-1, sr, sc);
}


int countDistinctIslands(vector<vector<int>>&grid){

    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int,int>>>s;
    vector<pair<int,int>>v;

    for(int i=0; i<n; i++){
        for(int j=0 ;j<m; j++){//n*m *log(n*m) + dfs=(n*m*4)
            if(grid[i][j]==1){
                dfs(grid, v, i, j, i, j);
                s.insert(v);
                v.clear();
            }
        }
    }
    return s.size();
}

int main(){
    

    return 0;
}