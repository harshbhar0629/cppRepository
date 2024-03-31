// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include <bits/stdc++.h>
using namespace std;

int f(vector<int>&v,int left,int right,int i,int j){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int cost = 1e9;

    for(int k=i; k<=j; k++){
        int l = f(v, left, v[k], i, k-1);
        int r = f(v, v[k], right, k+1, j);
        cost = min(cost, l+r+right-left);
    }

    return dp[i][j] = cost;
}

int f1(vector<int>& v,int i,int j){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int cost = 1e8;
    for(int k=i; k<=j; k++){
        int l =  f1(v,i,k-1);
        int r =  f1(v,k+1,j);
        int c =  l+r-v[i-1]+v[j+1];
        cost = min(cost, c);
    }

    return dp[i][j] = cost;
}




int fbu(vector<int>&v,int stickLen){

    int n = v.size();
    v.push_back(stickLen);
    v.insert(v.begin(),0);
    sort(v.begin(),v.end());
    memset(dp,0,sizeof dp);

    
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i>j) continue;
            int cost = 1e9;
            for(int k=i; k<=j; k++){
                int l =  dp[i][k-1];
                int r =  dp[k+1][j];
                int c =  l+r-v[i-1]+v[j+1];
                cost = min(cost, c);
            }
            dp[i][j] = cost;
        }
    }
    return dp[1][n];
}

int f1(vector<int>&v,int len){
    sort(v.begin(),v.end());
    return f(v,0,n,0,v.size()-1);
}



int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int lrn;
    cin>>len;

    cout<<f1(v,len);


    return 0;
}