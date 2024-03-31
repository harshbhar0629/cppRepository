#include <bits/stdc++.h>
using namespace std;


class Solution {

    int dp[4][500005];
    int f(vector<int>&v,int i,int currLane){
        if(i+1==v.size()) return 0;
        if(dp[currLane][i]!=-1) return dp[currLane][i];

        if(currLane!=v[i+1]) return dp[currLane][i] = f(v,i+1,currLane);
        else{
            int ans = INT_MAX;
            for(int j=1; j<=3; j++){
                if(currLane!=j){
                    int a = INT_MAX;
                    if(v[i+1]!=j and v[i]!=j) a = 1 + f(v,i,j);
                    ans = min(ans,a);
                }
            }
            return dp[currLane][i] = ans;
        }
    }

    int fbu(vector<int>&v){
        
        memset(dp,1e9, sizeof dp);
        int n = v.size()-1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int i=n-1; i>=0; i--){
            for(int currLane=1; currLane<=3; currLane++){
                if(currLane!=v[i+1]) dp[currLane][i] = dp[currLane][i+1];
                else{
                    int ans = 1e9;
                    for(int j=1; j<=3; j++){
                        if(currLane!=j){
                            int a = 1e9;
                            if(v[i] != j) a = 1 + dp[j][i+1];//i+1 bcoz may be possible ith column is not computed first so i+1 always computed thats why it depend on i+1 column 
                            ans = min(ans,a);
                        }
                    }
                    dp[currLane][i] = ans;
                }
            }
        } 
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }  

public:
    int minSideJumps(vector<int>& obstacles) {
        // memset(dp,-1,sizeof dp);
        // return f(obstacles,0,2);
        return fbu(obstacles);
    }
};

int main(){
    

    return 0;
}