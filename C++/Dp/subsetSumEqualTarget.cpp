#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


bool f(vector<int>&v,int sum,int i){    
    if(sum==0) return true;
    if(i==v.size()-1){
        if(v[i]== sum) return true; 
        else return false;
    }
    if(i>=v.size() || sum<0) return  false;

    return f(v,sum-v[i],i+1) || f(v,sum,i+1); 
}


vector<int>dp;
bool ftd(vector<int>&v , int sum,int i){
    if(sum==0) return true;
    if(i==v.size()-1){
        if(v[i]== sum) return true; 
        else return false;
    }
    if(i>=v.size() || sum<0) return false;
    if(dp[sum]!=-1) return dp[sum];
    
    return dp[sum] = ftd(v,sum-v[i],i+1) || ftd(v,sum,i+1);
}


bool fbu(vector<int>&v , int sum){
    int n = v.size();
    bool d[n+1][sum+2];
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++){
        d[i][0] = true;
    }
    d[0][v[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            bool take = false;
            bool notTake = d[i-1][j];
            if(v[i]<=j){
                take = d[i-1][j-v[i]];
            }
            d[i][j] = take | notTake;
        }
    }
    
    return d[n-1][sum];
}



bool fbuOpt(vector<int>&v , int sum){
    int n = v.size();
    vector<int> prev(sum+2,0) , curr(sum+2,0);
    // memset(d,0,sizeof(d));
    prev[v[0]] = prev[0] = curr[0] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            bool take = false;
            bool notTake = prev[j];
            if(v[i]<=j){
                take = prev[j - v[i]];
            }
            curr[j] = take | notTake;
        }
        prev = curr;
    }
    
    return prev[sum];
}


int main(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int sum;
    cin>>sum;
// 1 2 3 5 17 6 14 12 6
    dp.resize(sum+2,-1);
    // cout<<f(v,sum,0)<<endl;
    
    cout<<ftd(v,sum,0);

    // cout<<fbu(v,sum);

    // cout<<fbuOpt(v,sum);

    return 0;


}