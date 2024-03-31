// https://leetcode.com/problems/longest-common-subsequence/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>>dp;
int ftd(string &s,string &t,int i,int j){
    
    if(i==s.size() || j==t.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s[i]==t[j]){
        return dp[i][j] = 1 + ftd(s,t,i+1,j+1);
    }
    else{
        return dp[i][j] = max(ftd(s,t,i+1,j) , ftd(s,t,i,j+1));
    }
}


int fbu(string &s,string &t){

    dp.resize(1005,vector<int>(1005,0));
    int n = s.size(), m = t.size();

    for(int i = 0; i<=n; i++ ){
        for(int j=0; j<=m; j++){

            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );
            }
        }
    }

    for(int i = 0; i<=n; i++ ){
        for(int j=0; j<=m; j++){
            cout<<dp[i][j]<<"  ";
           
        }cout<<endl;
    }
   
    string ans ="";
    int i=n,j=m;
    while(i>0 and j>0){
        if(s[i-1]==t[j-1]){
            ans = s[i-1] + ans;
            i--, j--;
        }
        else if(dp[i-1]>dp[j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<ans;

    return dp[n][m];
}


void lcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    
    int index = L[m][n];
 
    char lcs[index + 1];
    lcs[index] = '\0'; 
 
    int i = m, j = n;
    while (i > 0 && j > 0) {
    
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; 
            i--;
            j--;
            index--;
        }
 
        
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
 
    
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
    
}


int main(){
    string s,t;
    cin>>s>>t;

    // dp.resize(1005,vector<int>(1005,-1));
    cout<<fbu(s,t);

    return 0;
}