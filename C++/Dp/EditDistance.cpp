// https://leetcode.com/problems/edit-distance/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int dp[505][505];
int f(string &s,string &t,int i,int j){
    if(j==t.size()) return s.size()-i;
    if(i==s.size() ) return t.size()-j;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[i]) return dp[i][j] = f(s,t,i+1,j+1);
    return dp[i][j] = min({1+f(s,t,i+1,j+1) , 1+f(s,t,i+1,j) , 1+f(s,t,i,j+1)});
}



int fbu(string s,string t){
    memset(dp,0,sizeof dp);

    for(int j=0; j<t.size(); j++){
        int i = s.size();
        dp[i][j] = t.size()-j;
    }

    for(int i=0; i<s.size(); i++){
        int j = t.size();
        dp[i][j] = s.size() - i;
    }

    for(int i=s.size()-1; i>=0; i--){
        for(int j=t.size()-1; j>=0; j--){
            if(s[i]==t[i]) dp[i][j] = dp[i+1][j+1];
            dp[i][j] = min({ 1 + dp[i+1][j+1] , 1 + dp[i+1][j] , 1 + dp[i][j+1] });
        }
    }
    return dp[0][0];
}



int main(){
    string s,t;
    cin>>s>>t;

    // memset(dp,-1,sizeof(dp));
    // cout<<f(s,t,0,0);

    cout<<fbu(s,t);

    return 0;
}