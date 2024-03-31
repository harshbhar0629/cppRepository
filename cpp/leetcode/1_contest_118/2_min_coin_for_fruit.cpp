// https://leetcode.com/contest/biweekly-contest-118/problems/minimum-number-of-coins-for-fruits/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    //why dp bcoz we can also take prev item free 
    int dp[1005][1005];
    int f(vector<int>& prices, int i, int j){
        if(i==prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        //if ith item purchase then it will give price[i] coin and next ith item free
        int ans = prices[i] + f(prices, i+1, i+1);
        
        //if ith item free then we can also purchase previous free item 
        if(j>0){
            ans = min(ans, f(prices, i+1, j-1));
        }
        
        //return min from the all choices
        return dp[i][j] = ans;
    }
    
public:
    int minimumCoins(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, 0);
    }
};

int main(){
    

    return 0;
}