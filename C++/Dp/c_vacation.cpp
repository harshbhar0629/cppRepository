#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int f(vector<vector<int>>&v,int i,int j){

    if(i>=v.size()) return 0;

    int mini = INT_MIN;
    for(int idx=0; idx<3; idx++){
        if(idx==j) continue;
        mini = max(mini, v[i][idx] + f(v,i+1,idx));
    }
    return mini;
}


vector<vector<int>>dp;
int ftd(vector<vector<int>>&v,int i,int j){

    if(i>=v.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MIN;
    for(int idx=0; idx<3; idx++){
        if(idx==j) continue;
        mini = max(mini, v[i][idx] + ftd(v,i+1,idx));
    }
    return dp[i][j] = mini;
}


int fbu(vector<vector<int>>&v){

    int n = v.size();
    for(int i=1; i<v.size(); i++){
        int a = max(v[i-1][1] , v[i-1][2]);
        int b = max(v[i-1][0] , v[i-1][2]);
        int c = max(v[i-1][0] , v[i-1][1]);
        v[i][0] = v[i][0] + a;
        v[i][1] = v[i][1] + b;
        v[i][2] = v[i][2] + c;
    }   
    return max({v[n-1][0] , v[n-1][1] , v[n-1][2]});

    // return max(v[n-1][0] , max(v[n-1][1] , v[n-1][2]) );
}


int main(){

    int n ;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3));
   
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>v[i][j];
        }
    }   
    // dp.clear();
    // dp.resize(n+1,vector<int>(4,-1));
    cout<<fbu(v);

    return 0;
}
/**
 * 3
10 40 70
20 50 80
30 60 90
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1


*/