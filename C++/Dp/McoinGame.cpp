// https://www.spoj.com/problems/MCOINS/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<bool>dp;
    int k,l;
    cin>>k>>l;    
    cout<<"No of terms: ";
    int m;
    cin>>m;

    dp.resize(1000005,0);
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;

    for(int i=2; i<=1000002; i++){
        if(i==k || i==l) continue;
        dp[i] = !(dp[i-1] and ((i-k >= 1) ? dp[i-k] : 1) and ((i-l >= 1) ? dp[i-l] : 1));
    }
//     2 3 5 
// 3 12 113 25714 88888

    for(int i=0 ;i<m; i++){
        int j;
        cin>>j;
        if(dp[j]==1){
            cout<<"A"<<" ";
        }
        else{
            cout<<"B" <<" ";
        }
    }

    return 0;
}