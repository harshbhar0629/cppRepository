// https://www.spoj.com/problems/GNYR09F/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int f(int n,int k,int last){
    if(n==0){
        return 0;
    }
    if(n==1){
        if(k==0) return 1;
        return 0;
    }

    int ans =0;
    if(last == 1){
        return f(n-1,k-1,1) + f(n-1,k,0);
    }
    else{
        return f(n-1,k,0) + f(n-1,k,1);
    }
}


int dp[1004][104][2];
int ftd(int n,int k,int last){
    if(n==0){
        return 0;
    }
    if(n==1){
        if(k==0) return 1;
        return 0;
    }
    if(dp[n][k][last]!=-1) return dp[n][k][last];

    int ans =0;
    if(last == 1){
        return dp[n][k][last] = ftd(n-1,k-1,1) + ftd(n-1,k,0);
    }
    else{
        return dp[n][k][last] = ftd(n-1,k,0) + ftd(n-1,k,1);
    }
}



/**
 * Input:
10
1 5 2
2 20 8
3 30 17
4 40 24
5 50 37
6 60 52
7 70 59
8 80 73
9 90 84
10 100 90

Output:
1 6
2 63426
3 1861225
4 168212501
5 44874764
6 160916
7 22937308
8 99167
9 15476
10 23076518

*/

int main(){
    int n,k;
    cin>>n>>k;

    // int ans = f(n,k,0) + f(n,k,1);
    // cout<<ans;

    memset(dp,-1,sizeof dp);
    cout<<(ftd(n,k,0) + ftd(n,k,1));

    return 0;
}