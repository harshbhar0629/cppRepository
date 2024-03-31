#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll N = 1e9+7; 
class Solution{
    
    int dp[1005][1005];
    ll f(string& s, int i, int j){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){    //abcda  then make calls for (abcd  or bcda)
            ll a = f(s, i+1, j)%N; 
            ll b = f(s, i, j-1)%N;
            return dp[i][j] = (1 + a+b)%N;
        }
        else{
            //abcda  then make calls for (abcd  or bcda)
            ll a = f(s, i+1, j)%N;
            ll b = f(s, i, j-1)%N;
            ll c = f(s, i+1, j-1)%N; //but if we observe in both calls bcd is common so we don't want to 
            // add same sub prblm it will count twice so deduct one time
            return dp[i][j] = (N + a + b - c)%N;
        }
    }
    
    public:
    /*You are required to complete below method */
    ll  countPS(string str){
        memset(dp, -1, sizeof dp);
        return f(str, 0, str.size()-1)%N;
    }
     
};


int main(){
    string s;
    cin>>s;
    // cout<<count_palindromic_sub(s);

    return 0;
}