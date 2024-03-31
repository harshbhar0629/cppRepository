// https://leetcode.com/problems/number-of-islands/
// https://leetcode.com/problems/rotting-oranges/description/
#include <bits/stdc++.h>
using namespace std;

// TC: n^2
void dfs(vector<vector<char>>&grid, int r, int c){
    int n = grid.size();
    int m = grid[0].size();
    if(r<0 || c<0 || r>=n || c>=m) return ;
    if(grid[r][c]=='0' || grid[r][c]=='2') return;

    grid[r][c] = '2';

    dfs(grid, r+1, c);
    dfs(grid, r-1, c);
    dfs(grid, r, c-1);
    dfs(grid, r, c+1);
}


int numIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int cntIsland=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1'){
                cntIsland++;
                dfs(grid, i, j);
            }
        }
    }
    return cntIsland;
}


int main(){
    

    return 0;
}