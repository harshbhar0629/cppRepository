#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution
{
    int dp[1005][1005];

    // int f(string& s, string &t, int i, int j){
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

    //     return dp[i][j] = max({exc1, exc2, inc});
    // }

public:
    string shortestCommonSupersequence(string s, string t)
    {
        // memset(dp, -1, sizeof dp);
        // cout<<( s.size() + t.size() - f(s, t, 0, 0));
        const int m = t.size();
        const int n = s.size();
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string res = "";
        int i = n, j = m;

        while (i > 0 and j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                res += s[i - 1];
                i--, j--;
            }
            else if (dp[i][j - 1] < dp[i - 1][j])
            {
                res += s[i - 1];
                i--;
            }
            else
            {
                res += t[j - 1];
                j--;
            }
        }

        while (i > 0)
        {
            res += s[i - 1];
            i--;
        }
        while (j > 0)
        {
            res += t[j - 1];
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    

    return 0;
}