// https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>
using namespace std;

// int large(int n){
//     vector<int>v(10,0);
//     while(n){
//         int x = n%10;
//         v[x]++;
//         n/=10;
//     }
//     for(int i=9; i>=0; i--){
//         if(v[i]!=0) return i;
//     }
//    return -1;
// }

// int a =0;
// int steps(int n){
//     cout<<n<<"  ";
//     if(n==0) return 0;
//     if(n<=9) return 1;
    
//     int ans = steps(n-large(n));
    
//     a = 1+max(a,ans);
//     return a;
// }

vector<int> getDigit(int n){
    vector<int>a;
    while(n){
        if(n%10!=0){
            a.push_back(n%10);
        }
        n/=10;
    }
    return a;
}

int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;

    vector<int>v= getDigit(n);
    int ans = INT_MAX;
    for(int i=0;i<v.size(); i++){
        ans = min(ans,f(n-v[i]));
    }
    return 1+ans;
}

vector<int>dp;

int ftd(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];

    vector<int>v= getDigit(n);
    int ans = INT_MAX;
    for(int i=0;i<v.size(); i++){
        ans = min(ans,ftd(n-v[i]));
    }
    return dp[n] = 1+ans;
}


int fbu(int n){
    dp.resize(n+100,-1);
    dp[0] = 0;
    for(int i=1;i<=9; i++){
        dp[i]=1;
    }

    for(int i=10; i<=n ; i++){
        vector<int>v = getDigit(i);
        int ans =INT_MAX;
        for(int j=0;j<v.size();j++){
            ans = min(ans , dp[i-v[j]]); 
        }
        dp[i] = 1+ans;
    }

    return  dp[n];
}

int main(){
    int n;
    cin>>n;
    
    // dp.resize(n+1000,-1);
    // cout<<ftd(n);
    
    // cout<<f(n);
    // cout<<steps(n);
   
    cout<<fbu(n);

    return 0;
}