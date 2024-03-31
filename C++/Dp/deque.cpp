// https://atcoder.jp/contests/dp/tasks/dp_l
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int



ll f(vector<ll>&v,int i,int j){
    if(i == j) return v[i];

    return max(v[i] - f(v,i+1,j),v[j] - f(v,i,j-1));
}



vector<vector<ll>>dp;
ll ftd(vector<ll>&v,int i,int j){
    if(i == j) return v[i];
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = max(v[i] - ftd(v,i+1,j),v[j] - ftd(v,i,j-1));
}


ll fbu(vector<ll>&v){
    int n = v.size();
    dp.resize(3005,vector<ll>(3005,0));

    for(int i=0;i<n;i++){
        dp[i][i] = v[i];
    }

    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j= i+len-1;
            dp[i][j] = max(v[i] - dp[i+1][j],v[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


int main(){

    // int n;
    // cin>>n;

    // vector<ll>v(n);
    // for(int i=0; i<n; i++){
    //     cin>>v[i];
    // }


    // // cout<<f(v,0,n-1);
 
    // // dp.resize(3005,vector<ll>(3005,-1));
    // // cout<<ftd(v,0,n-1);

    // cout<<fbu(v);

    return 0;
}