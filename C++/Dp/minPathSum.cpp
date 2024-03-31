// https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int f(vector<vector<int>>& v,int i,int j){

    if(i==v.size()-1 and j== v[0].size()-1){
        return v[i][j];
    }
    if(i>=v.size() || j>=v[0].size()) return 1e7;

    int a = v[i][j] + f(v,i+1,j);
    int b= v[i][j] + f(v,i,j+1);
    return min(a,b);

}

vector<vector<int>>dp;
int ftd(vector<vector<int>>& v,int i,int j){

    if(i==v.size()-1 and j== v[0].size()-1){
        return v[i][j];
    }
    if(i>=v.size() || j>=v[0].size()) return 1e7;
    if(dp[i][j]!=-1) return dp[i][j];

    int a = v[i][j] + f(v,i+1,j);
    int b= v[i][j] + f(v,i,j+1);
    return dp[i][j] = min(a,b);

}



int fbu(vector<vector<int>>& v){

    int n = v.size();
    int m = v[0].size();
    dp.resize(n,vector<int>(m,0));
    // dp[0][0] = v[0][0];

    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0 ) dp[0][0] = v[0][0];
            else{
                int up = 1e7, left = 1e7;
                if(i>0){
                    up = v[i][j] + dp[i-1][j];
                } 
                if(j>0){
                    left = v[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];

}


int fbuOpt(vector<vector<int>>&v){
    int n = v.size();
    int m = v[0].size();
    vector<int>prev(m,0);

    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                temp[j] = v[i][j];
            }
            else{
                int up= 1e5,left=1e5;
                if(i>0) up = v[i][j] + prev[j];
                if(j>0) left = v[i][j] + temp[j-1];
                temp[j] = min(up,left);
            }
        }
        prev = temp;
    }
    return prev[m-1];
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
   

   cout<<f(v,0,0)<<endl;

    dp.resize(n,vector<int>(m,-1));
    cout<<ftd(v,0,0)<<endl;

    cout<<fbu(v)<<endl;

    cout<<fbuOpt(v)<<endl;

    return 0;
}