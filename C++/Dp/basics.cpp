#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;

// recurive solution known as top down solution 
int f(int n ){
    // base case
    if(n==0 || n==1) return n;

    // checking this sub problem is already solved or not if yes then return ans
    if(dp[n] != -1) return dp[n];

    // fun call
    return dp[n] = f(n-2) + f(n-1);
}

// bottom up solution known as iterative solution
int f2(int n ){

    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }

    return dp[n];
} 

// by maintaining only last two value only
int f3(int n){
    if(n==1 || n==0) return n;
    int a =1 , b=0, c=0, i=2 ;
 
    while(i<=n){
        c = a+b;
        b= a;
        a =c;
        i++;
    }
    return c;
}

int main(){
    dp.clear();
    int n ;
    cin>>n;
    // it contains n num so that why n+1 size is assigned 
    dp.resize(n+1,-1);
    // cout<<n<<"th fib is: "<<f(n);
    // cout<<n<<"th fib is: "<<f2(n)<<endl;
    cout<<n<<"th fib is: "<<f3(n)<<endl;

    return 0;
}