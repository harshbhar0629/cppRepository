// https://leetcode.com/problems/01-matrix/
// https://leetcode.com/problems/number-of-enclaves/description/
#include <bits/stdc++.h>
using namespace std;

int updateMatrix(vector<vector<int>>& mat){

    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>> qu;
    vector<vector<int>> dis(n,vector<int>(m,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
                qu.push({i,j});
                dis[i][j] = 0;
            }
        }
    }

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    while(not qu.empty()){
        int i = qu.front().first;
        int j = qu.front().second;
        for(int k=0; k<4; k++){
            int r = i+dir[k].first;
            int c = j+dir[k].second;

            if(r<0 || c<0 || r>=n || c>=m) continue;
            if(dis[r][c]==-1){
                qu.push({r,c});
                dis[r][c] = dis[i][j]+1;
            }
        }
    }

    return dis;
}


int main(){
    

    return 0;
}