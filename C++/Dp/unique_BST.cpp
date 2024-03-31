#include <iostream>
#include <vector>
using namespace std;


int f(int n){
    if(n<=1) return 1;
    if(n==2) return 2;
    int ans =0;
    for(int i=1; i<=n; i++){
        ans+= f(i-1) * f(n-i);
    }
    return ans;
}



vector<int>dp;
int ftd(int n){
    if(n<=1) return 1;
    if(n==2) return 2;
    if(dp[n]!=-1) return dp[n];

    int ans =0;
    for(int i=1; i<=n; i++){
        ans+= ftd(i-1) * ftd(n-i);
    }
    
    return dp[n] = ans;
}



int fbu(int n){
    dp.resize(n+5,0);
    dp[0]=dp[1] = 1;
    dp[2] =2;
    for(int i=3;i<=n;i++){
        for(int k=1;k<=i;k++){
            dp[i]+=dp[k-1]*dp[i-k];
        }
    }
    return dp[n];
}



int main(){
    
    int n ;
    cin>>n;

    // cout<<f(n);

    // dp.resize(n+5,-1);
    // cout<<ftd(n);

    cout<<fbu(n);

    return 0;
}