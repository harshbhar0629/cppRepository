#include <bits/stdc++.h>
using namespace std;


int dp[305][305];
int f(vector<int>&v,int i,int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int cost = -1e9;
    for(int k=i; k<j; k++){
        int left = f(v,i,k);
        int right = f(v,k+1,j);
        cost = max(cost,(left+right+ v[i-1]*v[j]*v[k]));
    }
    return dp[i][j] = cost;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n+2);
    v[0] = v[n+1];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    memset(dp,-1,sizeof dp);
    cout<<f(v);

    return 0;
}