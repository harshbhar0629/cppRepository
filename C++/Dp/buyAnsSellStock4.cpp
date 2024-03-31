#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int f(vector<int>&v,int i,int k,bool on){
    if(i>=v.size()) return 0;

    int a = f(v,i+1,k,on);
    if(on){
        a = max(a, v[i] + f(v,i+1,k-1,false));
    }
    else if(k>0){
        a = max(f(v,i+1,k,true) - v[i],a);
    } 
    return a;
}
// [3,2,6,5,0,3]   k=2




int dp[105][15][2];
int ftd(vector<int>&v,int i,int k,bool on){
    if(i>=v.size()) return 0;
    if(dp[i][k][on]!=-1) return dp[i][k][on];

    int a = ftd(v,i+1,k,on);
    if(on){
        a = max(a, v[i] + ftd(v,i+1,k-1,false));
    }
    else {
        if(k>0)
            a = max(ftd(v,i+1,k,true) - v[i],a);
    } 
    return dp[i][k][on] = a;
}


int main(){
    int n;
    cin>>n;    

    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int k;
    cin>>k;

    // cout<<f(v,0,k,false);

    memset(dp,-1,sizeof dp);
    cout<<ftd(v,0,k,false);
    return 0;
}