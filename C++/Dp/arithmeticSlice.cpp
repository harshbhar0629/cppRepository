// https://leetcode.com/problems/arithmetic-slices/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// [1,2,3,4] ->> 3

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    if(n<3) cout<<"0";

// in case of subarray ans will lie on the prev we don't have to fight more
    vector<int>dp(n,0);
    for(int i=2;i<n;i++){
        if(v[i]-v[i-1] == v[i-1]-v[i-2]){
            dp[i] = dp[i-1] + 1;
        }
    }
    
    int ans = accumulate(dp.begin(),dp.end(),0);
    cout<<ans; 

    return 0;
}