// https://leetcode.com/problems/coloring-a-border/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<pair<int,int>>v;

    void dfs(vector<vector<int>>&grid, int r, int c, int color, int orgColor){
        int n = grid.size();
        int m = grid[0].size();
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]!=orgColor ) return;

        grid[r][c] = -color;

        dfs(grid, r+1, c, color, orgColor);
        dfs(grid, r-1, c, color, orgColor);
        dfs(grid, r, c-1, color, orgColor);
        dfs(grid, r, c+1, color, orgColor);

        if(not(r==0 || c==0 || r==n-1 || c==m-1 || grid[r+1][c] != -color || grid[r-1][c] != -color ||  grid[r][c-1] != -color || grid[r][c+1] != -color )){
            v.push_back({r,c});
        }
       
    }
   
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int color) {
        
        int orgColor = grid[r][c];
        if(orgColor == color) return grid;
        dfs(grid, r, c, color, orgColor);

        for(auto p: v){
            int i = p.first;
            int j = p.second;
            grid[i][j] = orgColor;
        }

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]<0){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;
    }
};


int main(){
    

    return 0;
}