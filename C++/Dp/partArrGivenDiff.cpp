// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?leftPanelTab=0
// target sum similar
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007



vector<vector<int>>dp;
int f(vector<int>&v,int i ,int target){
    if(i==v.size()-1){
        if(target==0 and v[i]==0) return 2;
        if(target==0 || v[i]==target) return 1;
        return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];

    return dp[i][target] = ((f(v,i+1,target)%mod) + (((v[i] <= target)?  f(v,i+1,target-v[i]) : 0)%mod))%mod;
}



int fbu(vector<int>&v,int target){
    dp.resize(55,vector<int>(2505,0));
    int n = v.size();
    if(v[n-1]==0){
        dp[n-1][0] = 2;
    }
    else{
        dp[n-1][0] = 1;
    }

    if(v[n-1]!=0 and v[n-1]<=target) dp[n-1][v[n-1]] = 1;

    for(int i= n-2; i>=0; i--){
        for(int j=0; j<=target; j++){
            int notTake =  dp[i+1][j]%mod ;
            int take =0;
            if(j>=v[i]){
                take = dp[i+1][j-v[i]]%mod ;
            }
            dp[i][j] =( take + notTake)%mod;

        }
    }
    return dp[0][target]%mod;

}



int main(){
    
    int n;
    cin>>n;
    int diff;
    cin>>diff;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int sum = accumulate(v.begin(),v.end(),0);

    // if( sum-diff < 0  ||  (sum - diff)%2) cout<<"0\n";
    // else{
    //     dp.clear();
    //     dp.resize(55,vector<int>(2505,-1));
    //     cout<<f(v,0,(sum-diff)/2) % mod;
    // }

    if( sum-diff < 0  ||  (sum - diff)%2) cout<<"0\n";
    else{
        cout<<fbu(v,(sum-diff)/2) % mod;
    }

    return 0;
}

// 2
// 4 3
// 5 2 6 4
// 4 0
// 1 1 1 1

// 1 6