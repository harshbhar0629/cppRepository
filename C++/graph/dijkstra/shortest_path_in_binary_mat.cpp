// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
#include <bits/stdc++.h>
using namespace std;


#define pp pair<int,int>
#define ppp pair<int,pp>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0]==1) return -1;
        int n = grid.size();
        if(n==1 and grid[0][0]==0) return 1;

        auto isSafe = [&](int x,int y){
            if(x<0 || y<0 || x>=n ||y>=n) return false;
            return true;
        };

        vector<pp>dir = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
        priority_queue<ppp,vector<ppp>,greater<ppp>>pq;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        dis[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int d=0; d<8; d++){
                int i = r+dir[d].first;
                int j = c+dir[d].second;
                if(isSafe(i,j) and grid[i][j]==0 and dis[i][j] > dis[r][c] + 1){
                    dis[i][j] = 1+dis[r][c];
                    grid[i][j] = 1;
                    pq.push({dis[i][j],{i,j}});
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX) return -1;
        return dis[n-1][n-1]+1;
    }
};
/*
#define pp pair<int,int>
#define ppp pair<int,pair<int,int>>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        if(n==1 and grid[0][0]==0) return 1;

        queue<ppp>q;
        q.push({0,{0,1}});
        vector<pp>dir = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}};

        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second.first;
            int step = cell.second.second;
            for(int d=0; d<8; d++){
                int i = r + dir[d].first;
                int j = c + dir[d].second;
                if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=0) continue;
                q.push({i,{j,step+1}});
                if(i==n-1 and j==n-1) return step+1;
                grid[i][j] = -1;
            }
        }
       
        return -1;
    }
};
*/


int main(){


    return 0;
}