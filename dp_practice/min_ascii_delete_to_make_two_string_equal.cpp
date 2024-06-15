#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution
{
    int dp[1005][1005];
    int f(const string &s, const string &t, int i, int j)
    {
        if (i == s.size() || j == t.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int exc1 = f(s, t, i + 1, j);
        int exc2 = f(s, t, i, j + 1);
        int inc = 0;

        if (s[i] == t[j])
        {
            inc = s[i] + f(s, t, i + 1, j + 1);
        }

        return dp[i][j] = max({exc1, exc2, inc});
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {
        int score1 = 0, score2 = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            score1 += s1[i];
        }
        for (int i = 0; i < s2.size(); i++)
        {
            score2 += s2[i];
        }
        memset(dp, -1, sizeof dp);
        return score1 + score2 - 2 * f(s1, s2, 0, 0);
    }
};

int main(){
    

    return 0;
}