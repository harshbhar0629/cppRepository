#include <bits/stdc++.h>
using namespace std;


int f(vector<int>&v){
    
    int n = v.size();
    vector<int>dp(n), count(n);
    int maxi=1;

    for(int i=0;i<n;i++){
        for(int j=0; j<i ;j++){
            if(v[j]<v[i] and dp[i]<dp[j]+1){
                count[i] = count[j];
                dp[i] = dp[j] + 1;
            }
            else if(v[j]<v[i] and dp[i]==dp[j]+1){
                count[i] += count[j];
            }
        }
        maxi = max(maxi,dp[i]);
    }

    int ans = 0;
    for(int i=0; i<n ;i++){
        if(dp[i]==maxi){
            ans+=count[i];
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<f(v);

    return 0;
}