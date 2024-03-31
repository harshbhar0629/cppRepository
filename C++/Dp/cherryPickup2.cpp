// https://leetcode.com/problems/cherry-pickup-ii/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int dp[72][72][72];
#define lli long long int
// TC->3^n*3^n
int f(vector<vector<int>>&v,int n,int m,int i,int j1,int j2){
    if(j1<0 || j2<0 || j1>m || j2>m) return -1e5;
    if(i==n-1){
        if(j1==j2) return v[i][j1];
        else return v[i][j1] + v[i][j2];
    }

    lli maxi = -1e5;
    for(int k=-1; k<=+1; k++){
        for(int l=-1; l<=+1; l++){
            lli val=0;
            if(j1==j2) val = v[i][j1];
            else val = v[i][j1] + v[i][j2];
            val += f(v,n,m,i+1,j1+k,j2+l);
            maxi = max(maxi,val);
        }
    }
    return maxi;
}


/// @brief 
/// @param v input vector
/// @param n no. of row
/// @param m no. of column
/// @param i point to ith row or current row
/// @param j1 first man who pick choc from 0 to downward
/// @param j2 last man who pick choc from column-1 to downward
/// @return 

int ftd(vector<vector<int>>&v,int n,int m,int i,int j1,int j2){
    if(j1<0 || j2<0 || j1>m || j2>m) return -1e5;
    if(i==n-1){
        if(j1==j2) return v[i][j1];
        else return v[i][j1] + v[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e5;
    for(int k=-1; k<=+1; k++){
        for(int l=-1; l<=+1; l++){
            int val=0;
            if(j1==j2) val = v[i][j1];
            else val = v[i][j1] + v[i][j2];
            val += ftd(v,n,m,i+1,j1+k,j2+l);
            maxi = max(maxi,val);
        }
    }
    return dp[i][j1][j2] = maxi;
}


// TC->(n*m*m*9)
int fbu(vector<vector<int>>&v){

    int n = v.size();
    int m = v[0].size();
    memset(dp,0,sizeof dp);

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) dp[n-1][i][j] = v[n-1][j];
            else dp[n-1][i][j] = v[n-1][i] + v[n-1][j];
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){

                int maxi = -1e5;
                for(int k=-1; k<=+1; k++){
                    for(int l=-1; l<=+1; l++){

                        int val=0;
                        if(j1==j2) val = v[i][j1];
                        else val = v[i][j1] + v[i][j2];

                        if(j1+k<0 || j2+l<0 || j1+k>=m || j2+l>=m){
                            val +=-1e8;
                        }
                        else{
                            val += dp[i+1][j1+k][j2+l]; 
                        }
                        maxi = max(maxi,val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}


// [3,1,1],[2,5,1],[1,5,5],[2,1,1]
int main(){

    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // solution
    // cout<<f(v,n,m,0,0,m-1);

    // memset(dp,-1,sizeof dp);
    // cout<<ftd(v,n,m,0,0,m-1);

    cout<<fbu(v);

    return 0;
}