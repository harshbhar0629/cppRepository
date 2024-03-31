// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
       
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        int dist[n][m];
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                dist[i][j] = 1e8;
            }
        }
            
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        dist[0][0] = 0;

        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first; 
            int y = curr.second; 
            int wt = grid[x][y]; 

            for(int d=0; d<4; d++){
                int i = x + dx[d]; 
                int j = y + dy[d]; 

                int edgeWt = 1; 
                if(d+1==wt) edgeWt = 0;

                if(i>=0 and j>=0 and i<n and j<m){ 
                    if(dist[i][j] > dist[x][y] + edgeWt){
                        dist[i][j] = dist[x][y] + edgeWt; 
                        if(edgeWt==1){
                            dq.push_back({i,j});
                        }
                        else{
                            dq.push_front({i,j});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};


int main(){


    return 0;
}