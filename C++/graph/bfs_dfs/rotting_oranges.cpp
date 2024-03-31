// https://leetcode.com/problems/rotting-oranges/description/
#include <bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>qu;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2) qu.push({i,j});
        }
    }
    
    int minutes=0;
    vector<pair<int,int>> dir = {{0,1} , {0,-1}, {1,0},{-1,0}};

    while(not qu.empty()){
        int size = qu.size();

        for(int s=0; s<size; s++){
            int i = qu.front().first;
            int j = qu.front().second;
            qu.pop();
            grid[i][j]=5;
            for(int k=0; k<4; k++){
                int r = i + dir[k].first;
                int c = j + dir[k].second;
                if(r<0 || c<0 || r>=n || c>=m) continue;
                if(grid[r][c]!=1) continue;
                qu.push({r,c});
                grid[r][c] = 5;
            }
        }
        minutes++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1) return -1;
        }
    }

    if(minutes>0) return minutes-1;
    return minutes;
}


int main(){
    

    return 0;
}