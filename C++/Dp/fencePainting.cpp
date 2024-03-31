// https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208?leftPanelTab=1
#include <bits/stdc++.h> 
using namespace std;
int Mod = 1000000007;
int add(int n,int k){
    return ((n%Mod)+(k%Mod)%Mod);
}

int mult(int n,int k){
    return ((n%Mod)*1LL*(k%Mod)%Mod);
}

int solve1(int n,int k){
    if(n==1) return k;
    if(n==2){
        return add(k,mult(k,k-1))%Mod;
    }
    int ans = add(mult(k-1,solve1(n-2,k))%Mod , mult(k-1,solve1(n-1,k))%Mod );
     
    return ans%Mod;
}

vector<int>dp;
int solve2(int n,int k){
    if(n==1) return k;
    if(n==2){
        return add(k,mult(k,k-1))%Mod;
    }
    if(dp[n]!=-1) return dp[n];
    dp[n] = add(mult(k-1,solve2(n-2,k))%Mod , mult(k-1,solve2(n-1,k))%Mod );
     
    return dp[n]%Mod;
}


int fbu(int n, int k){
    dp.resize(n+100,-1);
    dp[1]=k;
    dp[2] = add(k,mult(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i] = add(mult(k-1,dp[i-2]) , mult(k-1,dp[i-1]));
    }
    return dp[n];
}


int fbuOpt(int n, int k){
   
    int prev2 = k;
    int prev1 = add(k,mult(k,k-1));

    for(int i=3;i<=n;i++){
        int curr = add(mult(k-1,prev2) , mult(k-1,prev1));
        prev2 = prev1;
        prev1= curr;
    }
    return prev1;
}


int numberOfWays(int n, int k) {
    // return solve1(n,k);
    dp.clear();
    dp.resize(n+100,-1);
    return solve2(n,k);
}