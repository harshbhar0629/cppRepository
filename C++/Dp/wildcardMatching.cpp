// https://leetcode.com/problems/wildcard-matching/description/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int dp[2005][2005];
bool f(string &s,string &t ,int i,int j){
    if(i==s.size() and j==t.size()) return true;
    if(j<t.size() and i==s.size()){
        for(; j<t.size(); j++){
            if(t[j]!='*') return false;
        }
        return true;
    }
    if(j==t.size() and i<s.size()) return false;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s[i]==t[j] or t[j]=='?'){
        return dp[i][j] = f(s,t,i+1,j+1);
    }
    if(t[j]=='*'){
        return dp[i][j] = f(s,t,i+1,j) or f(s,t,i,j+1);
    }

    return dp[i][j] = false;
}



bool fbu(string s,string t ){
    memset(dp,0,sizeof dp);
    int n = s.size();
    int m = t.size();

    for(int i=1; i<=n; i++){
        dp[i][0] = false;
    }
    bool flag = true;
    for(int j=1; j<=m; j++){
        if(t[j-1]!='*') {
            flag = false;
            break;
        }
        dp[0][j] = flag;
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1] or t[j-1]=='?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(t[j-1]=='*'){
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];

}




bool fbuOpt(string s,string t ){

    if(s==p) return true;
    if(p=="") return false;
    
    int n = s.size();
    int m = t.size();
    vector<int>prev(m+5,0),cur(m+5,0);


    bool flag = true;
    for(int j=1; j<=m; j++){
        if(t[j-1]!='*') {
            flag = false;
            break;
        }
        prev[j] = flag;
    }

    curr[0] = prev[0] = true;

    for(int i=1; i<=n; i++){
        if(i!=1){
            prev[0] = curr[0] = false;
        }
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1] or t[j-1]=='?'){
                curr[j] = prev[j-1];
            }
            else if(t[j-1]=='*'){
                curr[j] = prev[j] or curr[j-1];
            }
            else{
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];

}




int main(){
    string s ,t;
    cin>>s>>t;
    // memset(dp,-1,sizeof dp);
    // cout<<f(s,t,0,0);

    cout<<fbu(s,t);

    return 0;
}