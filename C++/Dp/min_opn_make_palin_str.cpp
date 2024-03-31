// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int f(string &s,string &t,int i,int j){
    if(i>=s.size() || j>=t.size()) return 0;
    if(s[i]==t[j]){
        return 1+f(s,t,i+1,j+1);
    }
    return max(f(s,t,i+1,j),f(s,t,i,j+1));
}



int dp[505][505];
int ftd(string &s,string &t,int i,int j){
    if(i>=s.size() || j>=t.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j] = 1+ftd(s,t,i+1,j+1);
    }
    return dp[i][j] = max(ftd(s,t,i+1,j),ftd(s,t,i,j+1));
}


 int fbu(string s,string t){

    vector<int>prev(505,0),curr(505,0);
    int n = s.size();

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){

            if(s[i]==t[j]){
                curr[j] = 1 + prev[j+1];
            }
            else{
                curr[j] = max(prev[j],curr[j+1]) ;
            }
        }
        prev = curr;
    }
    return curr[0];
}


int main(){
    string s;
    cin>>s;

    string t= s;
    reverse(s.begin(),s.end());

    // int ans = s.size() - f(s,t,0,0);
    // cout<<ans<<"\n";

    // memset(dp,-1,sizeof dp);
    // int ans2 = s.size() - ftd(s,t,0,0);
    // cout<<ans2<<"\n";

    return 0;
}