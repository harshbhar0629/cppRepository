#include <bits/stdc++.h>
using namespace std;
// it contains only L,R,U,D

int n ,m;
vector<vector<char>>grid;
// bool ans = false;

bool dfs(int i, int j, vector<vector<bool>>&visited){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    if(i==n-1 and j==m-1) return true;
    if(visited[i][j]==true) return false;

    visited[i][j] = 1;

    if(grid[i][j]=='r'){
        return dfs(i , j+1, visited);
    }
    else if(grid[i][j]=='l'){
        return dfs(i, j-1, visited);
    }
    else if(grid[i][j]=='u'){
        return dfs(i-1, j, visited);
    }
    else{
        return dfs(i+1, j, visited);
    }

}


bool canReachDest(){
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    return dfs(0, 0, visited);
    
    // return ans;/
}





int main(){
    cin>>n>>m;
    grid.resize(n,vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    cout<<canReachDest();

    return 0;
}