// https://leetcode.com/problems/longest-palindromic-subsequence/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int dp[50][50];
int f(string& s,string &t,int i,int j){
    if(i>=s.size() || j>=t.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j] = 1+ f(s,t,i+1,j+1);
    }
    return dp[i][j] = max(f(s,t,i+1,j),f(s,t,i,j+1));
}


int fbu(string s,string t){
    int n = s.size();
    int m = t.size();

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+ dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}


int main(){

    string s;
    cin>>s;
    string t= s;
    reverse(s.begin(),s.end());    

    memset(dp,-1,sizeof dp);
    cout<<f(s,t,0,0);

    cout<<fbu(s,t);

    return 0;
}