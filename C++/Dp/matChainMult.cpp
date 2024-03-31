// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?leftPanelTab=0
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int f(vector<int>&v,int i ,int j){
    if(i==j || i+1==j) return 0;
    int ans = 1e9;
    for(int k=i+1; k<j; k++){
        ans = min(ans,f(v,i,k) + f(v,k,j) + v[i]*v[j]*v[k]);
    }
    return ans;
}


vector<vector<int>>dp;
int ftd(vector<int>&v,int i ,int j){
    if(i==j || i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 1e8;
    for(int k=i+1; k<j; k++){
        ans = min(ans,ftd(v,i,k) + ftd(v,k,j) + v[i]*v[k]*v[j]);
    }

    return dp[i][j] = ans;
}



int fbu(vector<int>&v){
    int n = v.size();
    dp.resize(105,vector<int>(105,0));
    for(int len=3; len<=n; len++){
        for(int i=0; i+len-1<n; i++){
            int j = i+len-1;
            int ans = 1e8;
            for(int k=i+1; k<j; k++){
                ans = min(ans,dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}



int main(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int ans = f(v,0,n-1);
    cout<<ans;

    // dp.resize(105,vector<int>(105,-1));
    // cout<<ftd(v,0,n-1);

    // cout<<fbu(v);

    return 0;
}