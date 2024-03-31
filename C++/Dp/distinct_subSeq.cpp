// https://leetcode.com/problems/distinct-subsequences/description/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int ans=0;
int f(string& s,string& t,int i,int j){
    
    if(j==t.size()) {
        return 1;
    }
    if(i==s.size()) return 0;

    int ans =0;
    if(s[i]==t[j]){
        ans += f(s,t,i+1,j+1)+f(s,t,i+1,j);
    }
    else{
        ans += f(s,t,i+1,j);
    }
    return ans;
}



int dp[1005][1005];
int ftd(string &s,string& t,int i,int j){
    if((i==s.size() and j==t.size()) || j==t.size()) return 1;
    if( i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j] = ftd(s,t,i+1,j+1) + ftd(s,t,i+1,j);
    }
    return dp[i][j] = ftd(s,t,i+1,j);
}


// use double it show runtime error while using (long long int or int)
int fbu(string s,string t){
    
    memset(dp,0,sizeof dp);
    int n =s.size();
    int m = t.size();

    for(int i=0; i<=n; i++){
        dp[i][m] = 1;
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s[i]==t[j]){
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
            }
            else{
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    return dp[0][0];
}



int main(){
    string s,t;
    cin>>s>>t;

    
    cout<<f(s,t,0,0);
  
    return 0;
}