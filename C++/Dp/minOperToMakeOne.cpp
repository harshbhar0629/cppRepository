#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
#define inf INT_MAX

int f(int n){
    if(n==1) return 0;
    if(n==0) return inf;
    int a = f(n-1);
    int b = (n%2==0)?f(n/2):inf;
    int c = (n%3==0)?f(n/3):inf;
    return 1+ min({a,b,c});
}

vector<int>dp;
int ftd(int n){
    if(n==1) return 0;
    if(n == 2 || n==3) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = 1+ min({ftd(n-1), (n%2==0)?ftd(n/2):INT_MAX, (n%3==0)?ftd(n/3):INT_MAX});
    return dp[n]; 
}

int fbu(int n){
    dp.resize(n+1,-1);
    dp[1]=0;
    dp[2]=dp[3]=1;

    for(int i=4;i<=n;i++){
        dp[i] = 1+ min({dp[i-1], (i%2==0)? dp[i/2] :INT_MAX, (i%3==0)? dp[i/3] :INT_MAX});
    }

    return dp[n]; 
}

int main(){

    int n ;
    cin>>n;
    
    cout<<fbu(n);    

    return 0;
}