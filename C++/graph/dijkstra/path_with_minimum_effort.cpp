// https://leetcode.com/problems/path-with-minimum-effort/
#include <bits/stdc++.h>
using namespace std;


#define pp pair<int,int>
#define ppp pair<int,pp>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        priority_queue<ppp,vector<ppp>,greater<ppp>>pq;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        
        dis[0][0] = 0;
        vector<pp>dir = {{0,1},{0,-1},{-1,0},{1,0}};
        pq.push({0,{0,0}});
        int mini = INT_MAX, maxi = INT_MIN;

        auto isSafe = [&](int x, int y){
            if(x<0 || y<0 || x>=n || y>=m) return false;
            return true;
        };

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int r = curr.second.first;
            int c = curr.second.second;
            int diff = curr.first;

            for(int d=0; d<4; d++){
                int i = r+ dir[d].first;
                int j = c+ dir[d].second;
                if(isSafe(i,j)) {
                    //we have to take max diff b/w adj cell but the overall effort should be minimum 
                    int m = max(diff,abs(heights[r][c] - heights[i][j]));
                    maxi = min(maxi,m);
                    if(m<dis[i][j]){
                        dis[i][j] = m;
                        pq.push({m, {i,j}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};


int main(){
    

    return 0;
}