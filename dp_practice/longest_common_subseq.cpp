#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-common-subsequence/
// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution
{
    int dp[1002][1002];
    // int f(const string& s, const string& t, int i, int j){
    //     if(i==s.size() || j==t.size()){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int exc1 = f(s, t, i+1, j);
    //     int exc2 = f(s, t, i, j+1);
    //     int inc = 0;
    //     if(s[i] == t[j]){
    //         inc = 1+ f(s, t, i+1, j+1);
    //     }

    //     return dp[i][j] = max({inc, exc1, exc2});
    // }
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, 0, sizeof dp);
        // return f(text1, text2, 0, 0);
        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size(); j >= 0; j--)
            {
                int exc1 = dp[i + 1][j];
                int exc2 = dp[i][j + 1];
                int inc = 0;
                if (text1[i] == text2[j])
                {
                    inc = 1 + dp[i + 1][j + 1];
                }

                dp[i][j] = max({inc, exc1, exc2});
            }
        }

        return dp[0][0];
    }
};

int main(){
    

    return 0;
}