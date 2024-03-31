// https://atcoder.jp/contests/dp/tasks/dp_b

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


// top down solution
vector<int> h;
int k;
int minCostToReachDestination(int i){
    // base cases
    
    // it cross the destination so it can't able to back so it haveto pay cost very high
    if(i >= h.size()) return INT_MAX;
    
    // reach our destination so now it don't have to pay any amount 
    if(i == h.size()-1) return 0;

    int ans = INT_MAX;
    for(int j = 1; j<=k; j++){
        if(i+j >= h.size()) break;
        // exploring all possible routes
        ans = min(ans , (abs(h[i] - h[i+j]) + minCostToReachDestination(i+j)) );
    }

    return ans;
}

// vector<int>dp(max constraint+3);
vector<int> dp;
int minCostToReachDestinationOptimised(int i){
    // base case

    // it cross the destination so it can't able to back so it haveto pay cost very high
    if(i >= h.size()) return INT_MAX;
    
    // reach our destination so now it don't have to pay any amount 
    if(i == h.size()-1) return 0;

    // check this jump is computrd or not 
    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for(int j = 1; j<=k; j++){
        if(i+j >= h.size()) break;
        // exploring all possible routes
        ans = min(ans , (abs(h[i] - h[i+j]) + minCostToReachDestinationOptimised(i+j)) );
    }
    return dp[i] = ans;
}


// bottom up solution

int minCostToReachDestinationBottomUp(){
    
    int n = h.size();
    dp.resize(n,1000000);
    dp[n-1] =0;
    for(int i= n-2; i>=0; i--){
        for(int j=1; j<=k; j++){
            if(i+j >= n) break;
            dp[i] = min(dp[i] , abs(h[i] - h[i+j]) + dp[i+j]);
        }
    }
    return dp[0];
}


int main(){

    int n;
    cin>>n>>k;
    h.resize(n);
    // dp.resize(n,-1); //for top down

    for(int i=0; i<n; i++){
        cin>>h[i];
    }   
    
    // top down solution
    // not optimised because of their repeatition
    // cout<<minCostToReachDestination(0)<<endl;
    // optimised
    // cout<<minCostToReachDestinationOptimised(0);

    cout<<minCostToReachDestinationBottomUp();
    

    return 0;
}

/**
 * inputs: 
 * 5 3
 * 10 30 40 50 20
 * 30
 * 
 * 3 1
 * 10 20 10
 * 20
 * 
 * 10 4
 * 40 10 20 70 80 10 20 70 80 60
 * 40
*/