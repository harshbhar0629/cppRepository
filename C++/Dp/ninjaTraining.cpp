#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int maxProfit(vector<vector<int>>&v, int j,int k){
    if(j>=v.size()) return 0;

    int maxi=0;
    for(int i=0; i<3; i++){
        if(k!=i)
        maxi = max(maxi, v[j][i] + maxProfit(v,j+1,i));
    }    
    return maxi;
}


vector<vector<int>>dp;
int maxProfitTD(vector<vector<int>>&v, int j,int k){
    if(j>=v.size()) return 0;
    if(k!=-1 and dp[j][k]!=-1) return dp[j][k];

    int maxi=0;
    for(int i=0; i<3; i++){
        if(k!=i)
        maxi = max(maxi, v[j][i] + maxProfitTD(v,j+1,i));
    }    
    return dp[j][k] = maxi;
}



int maxProfitBU(vector<vector<int>>&v){
    int n = v.size(); 
    dp.resize(n,vector<int>(4,0));
    dp[0][0] = max(v[0][1],v[0][2]);
    dp[0][1] = max(v[0][0],v[0][2]);
    dp[0][2] = max(v[0][0],v[0][1]);
    dp[0][3] = max({dp[0][1],dp[0][0],dp[0][2]});

    for(int i=1; i<n; i++){
        for(int j=0;j<4;j++){
            dp[i][j]=0;
            int a =0;
            
            for(int k=0;k<3;k++){
                if(k!=j)
                    a= max(a,v[i][k]+dp[i-1][k]);
            }
            dp[i][j] = a;
        }
    }
    return dp[n-1][3];
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;

    for(int i=0; i<n; i++){
        vector<int>a(3);
        for(int j=0; j<3; j++){
            cin>>a[j];
        }
        v.push_back(a);
    }    
    int k=-1;

    // int ans = maxProfit(v,0,k);
    // cout<<ans;

    // dp.resize(n+1,vector<int>(3,-1));   
    // cout<<maxProfitTD(v,0,k);

    cout<<maxProfitBU(v);

    return 0;
}