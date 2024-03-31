#include <bits/stdc++.h>
using namespace std;



int dp[10005][1];
int f(int n){
    if(n==0) return 0;
    // if(n<0) return 1e7;
    if(dp[n][0] != -1) return dp[n][0];

    int ans = n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans,1+f(n-i*i));
    }
    return dp[n][0] = ans;
}

int numSquares(int n) {
    memset(dp,-1,sizeof dp);
    return f(n);
}



int main(){
    

    return 0;
}