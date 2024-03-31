// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int dp[5005][2];
int f(vector<int>& prices,int i,bool flag){
    if(i>=prices.size()) return 0;
    if(dp[i][flag]!=-1) return dp[i][flag];

    if(flag){
        return dp[i][flag] = max(f(prices, i+1, flag) , prices[i] + f(prices, i+2, 0));
    }
    return dp[i][flag] = max(f(prices, i+1, flag) , f(prices, i+1, 1) - prices[i]);
}

// 1,2,3,0,2
int fbu(vector<int>&prices){
    memset(dp,0,sizeof dp);
    int n = prices.size();
    for(int i=n-1; i>=0; i--){
        for(int flag=0; flag<2; flag++){
            if(flag){
                dp[i][flag] = max(dp[i+1][flag] , prices[i] + dp[i+2][0] );
            }
            else{
                dp[i][flag] = max(dp[i+1][flag] , dp[i+1][1] - prices[i]);
            }    
        }
    }
    return dp[0][0];
}

int main(){

    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    // memset(dp,-1,sizeof dp);
    // cout<<f(prices,0,0);

    cout<<fbu(prices);

    return 0;
}