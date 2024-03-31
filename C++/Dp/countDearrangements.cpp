#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    int ans = (n-1)*(f(n-1) + f(n-2));
    return ans;
}


vector<int>dp;
int ftd(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];

    dp[n] = (n-1)*(ftd(n-1)+ftd(n-2));
    return dp[n];
}

int fbu(int n){
    dp.resize(n+10,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3;i<=n;i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}


int fbuOpt(int n){
    int a =0;
    int b=1;
    for(int i=3;i<=n;i++){
        int c = (i-1)*(b+a);
        a=b;
        b=c;
       
    }
    return b;
}


int main(){
    int n;
    cin>>n;
    // cout<<f(n);
    dp.resize(n+1,-1);
    cout<<ftd(n)<<endl;
    cout<<fbu(n)<<endl;
    cout<<fbuOpt(n)<<endl;

    return 0;
}