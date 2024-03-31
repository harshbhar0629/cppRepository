// https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int solve(int n , vector<int> cost){
        if(n==0 || n==1){
            return cost[n];
        }
        return cost[n] + min(solve(n-1,cost), solve(n-2,cost));
    }

    vector<int>dp;
    int solve2(int n , vector<int> cost){
        if(n==0 || n==1){
            return cost[n];
        }
        
        if(dp[n]!=-1) return  dp[n];

        dp[n] = cost[n] + min(solve2(n-1,cost),solve2(n-2,cost)); 
        return dp[n];
    }

    int solve3(int n , vector<int> cost){
        dp.resize(n+1);
        dp[0]= cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
    }

    int solve4(int n ,vector<int>cost){
        int prev1 = cost[0];
        int prev2 = cost[1];
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev2,prev1);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // int ans = min(solve(n-1,cost) , solve(n-2,cost));
        // return ans;

        // int n = cost.size();
        // dp.resize(n+1,-1);
        // int ans = min(solve2(n-1,cost), solve2(n-2,cost));
        // return ans;

        // int n = cost.size();
        // int ans = solve3(n,cost);
        // return ans;

        int n = cost.size();
        int ans = solve4(n,cost);
        return ans;
    }
};

int main(){
    

    return 0;
}