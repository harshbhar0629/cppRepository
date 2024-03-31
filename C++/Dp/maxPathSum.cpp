// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int f(vector<vector<int>>&v,int i,int j){
    
    if(j>=v[0].size()-1 || j<0 || i>=v.size()) return -1e4;
    if(i==v.size()-1) return v[i][j];

    return v[i][j] + max(f(v,i+1,j-1) ,max(f(v,i+1,j) ,f(v,i+1,j+1)));
}

vector<vector<int>> dp;
int ftd(vector<vector<int>>&v,int i,int j){
    
    if(j>=v[0].size()-1 || j<0 || i>=v.size()) return -1e4;
    if(dp[i][j] != -1 ) return dp[i][j];
    if(i==v.size()-1) return v[i][j];

    return dp[i][j] = v[i][j] + max(f(v,i+1,j) ,max(f(v,i+1,j-1) ,f(v,i+1,j+1)));
}

int fbu(vector<vector<int>>&v){
    
    int n = v.size();
    dp.clear();
    dp.resize(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        dp[0][i] = v[0][i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int a =0,b=0,c=0;
            if(j>0) a= dp[i-1][j-1] + v[i][j];
            else a = -1e7;
            b = dp[i-1][j] + v[i][j];
            if(j<n-1) c= dp[i-1][j+1] + v[i][j];
            else c= -1e7;
            dp[i][j] = max(a,max(b,c));
        }
    }

    int maxi =0;
    for(int j=0;j<n;j++){
        cout<<dp[n-1][j]<<" ";
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}



int fbuOpt(vector<vector<int>>&v){
    
    int n = v.size();
    vector<int>prev(n,0),cur(n,0);

    for(int i=0;i<n;i++){
        prev[i] = v[0][i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int a =0,b=0,c=0;
            if(j>0) a= prev[j-1] + v[i][j];
            else a = -1e7;
            b = prev[j] + v[i][j];
            if(j<n-1) c= prev[j+1] + v[i][j];
            else c= -1e7;
            cur[j] = max(a,max(b,c));
        }
        prev = cur;
    }

    int maxi =0;
    for(int j=0;j<n;j++){
        maxi = max(maxi,prev[j]);
    }
    return maxi;
}



int main(){
    int n ;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    int maxi=0;
    for(int i=0;i<n;i++){
        int ans = f(v,0,i);
        maxi = max(maxi,ans); 
    }

    cout<<maxi<<endl;

    // maxi=0;

    // dp.resize(n+1,vector<int>(n+1,-1));    
    // for(int j=0;j<n;j++){
    //     int ans = ftd(v,0,j);
    //     maxi = max(maxi,ans);
    // }
    // cout<<maxi<<endl;

    // cout<<fbu(v);

    return 0;
}