// https://leetcode.com/problems/pacific-atlantic-water-flow/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<vector<int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<bool>> bfs(queue<pair<int,int>>&qu, vector<vector<int>>& h){
        
        int n = h.size();
        int m = h[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int i = cell .first;
            int j = cell.second;
            visited[i][j] = 1;

            for(int k=0; k<4; k++){
                int r = i + dir[k][0];
                int c = j + dir[k][1];
                if(r<0 || c<0|| r>=n || c>=m) continue;
                if(h[i][j] > h[r][c] || visited[r][c]) continue;
                qu.push({r,c});
            }
        }
        return visited;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>>pac;
        queue<pair<int,int>>alt;
        for(int i=0; i<n; i++){
            pac.push({i,0});
            alt.push({i,m-1});
        }

        for(int j=1; j<m; j++){
            pac.push({0,j});
            alt.push({n-1,j-1});
        }

        vector<vector<bool>> pacific = bfs(pac,heights);
        vector<vector<bool>> atlantic = bfs(alt,heights);
        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};


int main(){
    

    return 0;
}