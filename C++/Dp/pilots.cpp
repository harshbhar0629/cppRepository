// https://www.spoj.com/problems/MPILOT/
#include <iostream>
#include <ctime>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

int n;
/// @brief 
/// @param captain 
/// @param assistant
/// @param ith
/// @param x denotes diff of assitant and captain 
/// @return 
int f(vector<int>& cap,vector<int>& ass,int i,int x){
    if(i==n) return 0;
    if(x==0){
        // if no on then add as a assistant because it is sort by age
        return ass[i] + f(cap,ass,i+1,x+1);
    }
    else if(x==n-i){
    // if captian is no more but assistant equal to n/2 so now we have to add only cap
        return cap[i] + f(cap,ass,i+1,x-1);
    }
    else{
        // take minimum of captian and assistant salary
        return min(ass[i]+f(cap,ass,i+1,x+1) , cap[i] + f(cap,ass,i+1,x-1));
    }
}


vector<vector<int>>dp;
/// @brief 
/// @param captain salary
/// @param assistant salary 
/// @param ith
/// @param x denotes diff of assitant and captain 
/// @return 
int ftd(vector<int>& cap,vector<int>& ass,int i,int x){
    if(dp[i][x]!=-1) return dp[i][x];
    if(i==n) return 0;
    if(x==0){
        // if no on then add as a assistant because it is sort by age
        return dp[i][x] = ass[i] + ftd(cap,ass,i+1,x+1);
    }
    else if(x==n-i){
    // if captian is no more but assistant equal to n/2 so now we have to add only cap
        return dp[i][x] = cap[i] + ftd(cap,ass,i+1,x-1);
    }
    else{
        // take minimum of captian and assistant salary
        return dp[i][x] = min(ass[i]+ftd(cap,ass,i+1,x+1) , cap[i] + ftd(cap,ass,i+1,x-1));
    }
}



/**
 * input 
    4 
    5000 3000 
    6000 2000 
    8000 1000 
    9000 6000 
    
    output 
    19000 

    input 
    6 
    10000 7000 
    9000 3000 
    6000 4000 
    5000 1000 
    9000 3000 
    8000 6000 
    
    output 
    32000
*/

int main(){
    clock_t begin = clock();
    #ifndef ONLINE_JUDGE
    clock_t end = CLOCKS_PER_SEC;
    cout<<"Executed in: "<<end-begin<<" ms\n";
    #endif

    // cin>>n;

    // vector<int>cap(n);
    // vector<int>ass(n);

    // for(int i=0;i<n;i++){
    //     cin>>cap[i]>>ass[i];
    // }

    // dp.resize(10005,vector<int>(5005,-1));
    // cout<< ass[0]+f(cap,ass,1,1);

    return 0;
}