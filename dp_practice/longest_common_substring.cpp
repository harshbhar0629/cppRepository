#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    int dp[1005][1005];
    int f(const string& s, const string& t, int i, int j, int & cnt){
        if(i == s.size() || j==t.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int skip1 = f(s, t, i+1, j, cnt);
        int skip2 = f(s, t, i, j+1, cnt);
        int inc = 0;
        if(s[i] == t[j]){
            int inc = 1+ f(s, t, i+1, j+1, cnt);
            cnt = max(cnt, inc);
            return dp[i][j] = inc;
        }
        else{
            return dp[i][j] = 0;
        }
    }
public:
    int longestCommonSubstr (string s, string t, int n, int m){
        memset(dp, 0, sizeof dp);
        int cnt = 0;
        // f(S1, S2, 0, 0, cnt);
        
        for(int i=s.size()-1; i>=0; i--){
            for(int j=t.size()-1; j>=0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                    if(cnt < dp[i][j]){
                        cnt = dp[i][j];
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        
        return cnt;
    }
};

int main(){
    

    return 0;
}