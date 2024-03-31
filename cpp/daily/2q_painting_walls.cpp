// https://leetcode.com/problems/painting-the-walls/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int dp[505][505];

    int f(vector<int>&cost, vector<int>&time, int idx, int remains){
        if(remains<=0) return 0;
        if(idx>=cost.size()) return 1e9;
        if(dp[idx][remains]!=-1) return dp[idx][remains];

        int a = cost[idx] + f(cost, time, idx+1, remains-time[idx]-1);
        int b = f(cost, time, idx+1, remains);

        return dp[idx][remains] = min(a,b);
    }

    int fbu(vector<int>& cost, vector<int>& time){
        int n = cost.size();
        memset(dp, 0, sizeof dp);

        for(int j=1; j<=n; j++){
            dp[n][j] = 1e9;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                int a = cost[i] + dp[i+1][max(0,j-1-time[i])] ;
                
                int b = dp[i+1][j];

                dp[i][j] = min(a,b);
            }
        }
        return dp[0][n];
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // memset(dp, -1, sizeof dp);
        return fbu(cost, time);
    }
};


int main(){
    

    return 0;
}