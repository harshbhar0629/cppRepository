#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int f(vector<int>&v,int i,int k,bool on){
    if(i>=v.size()) return 0;

    int ans = f(v,i+1,k,on);
    if(on){
        ans = max(ans,v[i] + f(v,i+1,k-1,false));
    }
    else if(k>0){
        ans = max(ans,f(v,i+1,k,true)-v[i]);
    }
    return ans;
}


int dp[1005][5][2];
int ftd(vector<int>&v,int i,int k,bool on){
    if(i>=v.size()) return 0;
    if(dp[i][k][on]!=-1) return dp[i][k][on];

    int ans = f(v,i+1,k,on);
    if(on){
        ans = max(ans,v[i] + ftd(v,i+1,k-1,false));
    }
    else if(k>0){
        ans = max(ans,ftd(v,i+1,k,true)-v[i]);
    }
    return dp[i][k][on] =  ans;
}


int fbu(vector<int>&v){
    // int k=2;
    int n = v.size();
    memset(dp,0,sizeof dp);

    for(int i=n-1; i>=0; i--){
        for(int k=1; k<=2; k++){
            for(int flag=0; flag<2; flag++){
                int ans = dp[i+1][k][flag];
                if(flag){
                    ans = max(ans,v[i] + dp[i+1][k-1][0]);
                }
                else if(k>0){
                    ans = max(ans, dp[i+1][k][1]-v[i]);
                }
                dp[i][k][flag] =  ans;
            }
        }
    }
    return dp[0][2][0];
}


// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6

int main(){

    int n;
    cin>>n;    

    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int k=2;
    // cin>>k;

    // cout<<f(v,0,k,false);

    // memset(dp,-1,sizeof dp);
    // cout<<ftd(v,0,k,false);    

    cout<<fbu(v);

    return 0;
}

/**
 *  int solve(vector<int>&prices, int day, int transactionsLeft){
        
        if(day == prices.size()){
            return 0;
        }
        
        if(transactionsLeft == 0){
            return 0;
        }
        
        // choice 1
        // no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft);
        
        
        // choice 2
        // doing the possible transaction today     
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);
        
        if(buy == true){ // buy
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        }else{ // sell
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        }
        
        return max(ans1, ans2);
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int ans = solve(prices, 0, 4); // starting with day 0 and max 4 transactions can be done
        return ans;
    }
*/