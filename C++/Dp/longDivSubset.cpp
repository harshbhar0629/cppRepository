// https://leetcode.com/problems/largest-divisible-subset/
#include <bits/stdc++.h>
using namespace std;


vector<int>dp;
int f(vector<int>&v,int i){
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    int maxi=-1;

    for(int j=0; j<i; j++){
        if(v[i]%v[j]==0){
            maxi = max(maxi,f(v,j));
        }
    }
    if(maxi==-1) return dp[i] = 1;
    return dp[i] = maxi+1;
}


vector<int> print(vector<int>&v){
    
    int n = v.size();
    dp.resize(n,1);
    vector<int>hash(n);
    int idx =0;
    int maxi = 1;
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int j=0; j<i; j++){
            if(v[i]%v[j] == 0 and dp[i] < dp[j]+1){
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if(maxi < dp[i]){
            maxi = dp[i];
            idx = i;
        }
    }

    vector<int>ans;
    ans.push_back(v[idx]);

    while(idx!=hash[idx]){
        idx = hash[idx];
        ans.push_back(v[idx]);
    }

    reverse(ans.begin(),ans.end());

    return ans;

}


int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }


    sort(v.begin(),v.end());
    int maxi=0;
    
    dp.resize(n+1,-1);
    for(int i=0;i<n;i++){
        maxi = max(maxi,f(v,i));
    }

    cout<<maxi<<endl;

    return 0;
}