// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fbu(vector<int>&v ){

    int n = v.size();
    int sum = accumulate(v.begin(),v.end(),0); 

    vector<vector<bool>> dp(n+1,vector<bool>(sum+2,false));

    for(int i=0;i<n;i++) {
        dp[i][0] = true;
    }

    if(v[0] <= sum) {
        dp[0][v[0]] = true;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){

            bool notTake = dp[i-1][j];
            bool take = false;
            if(v[i]<=j) take = dp[i-1][j-v[i]];
            dp[i][j] = take || notTake;
        }
    }

    int mini = 1e7;
    for(int i=0;i<=(sum+1)/2;i++){
    // it shows i can achieve a target or not if true then yes otherwise false
        if(dp[n-1][i] == true){
            int s1 = i;
            int s2 = sum-i;
            mini = min(mini, abs(s1-s2));
        }
    }

    return mini;
}


int fbuOpt(vector<int>&v ){

    int n = v.size();
    int sum = accumulate(v.begin(),v.end(),0); 

    vector<bool> prev(sum+2,0) , curr(sum+2,0);

    if(v[0] <= sum) {
        prev[v[0]] = true;
    }
    prev[0] = curr[0] = true;

    for(int i=1; i<n; i++){
        
        for(int j=1; j<=sum; j++){

            bool notTake = prev[j];
            bool take = false;
            if(v[i]<=j) take = prev[j-v[i]];
            curr[j] = take || notTake;
        }
        prev = curr;
    }

    int mini = 1e7;
    for(int i=0;i<=(sum+1)/2;i++){
        if(prev[i] == true){
            int s1 = i;
            int s2 = sum-i;
            mini = min(mini, abs(s1-s2));
        }
    }

    return mini;
}



int main(){
    
    int n=5;
    // cin>>n;
    vector<int>v={1,1,1,1,1};
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }

    cout<<fbu(v)<<endl;
    cout<<fbuOpt(v)<<endl;

    return 0;
}