// https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;


void solve(vector<vector<char>>&board){
    
    int  = board.size();
    int m = board.size();
    queue<pair<int,int>>q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0 || j==m-1 || i==n-1){
                if(board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
    }

    while(!q.empty()){
        auto cell = q.front();
        q.pop();
        int r = cell.first;
        int c = cell.second;
        board[r][c] = '#';

        for(int k=0; k<4; k++){
            int i = r+dir[k].first;
            int j = c+dir[k].second;

            if(i<0 || j<0 || j==m-1 || i==n-1 || board[i][j]!='O') continue;
            q.push({i,j});
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O'){
                board[i][j] ='X';                
            }
            else if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
        }
    }

}


int main(){
    

    return 0;
}