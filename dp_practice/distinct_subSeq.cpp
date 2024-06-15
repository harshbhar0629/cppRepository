#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/distinct-subsequences/description/

class Solution
{
    int dp[1005][1005];
    int f(const string &s, const string &t, int i, int j)
    {
        if (t.size() == j)
        {
            return 1;
        }
        if (s.size() == i)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int exc = f(s, t, i + 1, j);
        int inc = 0;
        if (s[i] == t[j])
        {
            inc = f(s, t, i + 1, j + 1);
        }

        return dp[i][j] = exc + inc;
    }

public:
    int numDistinct(string s, string t)
    {
        memset(dp, -1, sizeof dp);
        return f(s, t, 0, 0);
    }
};

int main(){
    

    return 0;
}