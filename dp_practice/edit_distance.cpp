#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/edit-distance/description/

class Solution
{
    int dp[505][505];
    int f(string &s, string &t, int i, int j)
    {
        if (i == s.size())
        {
            return t.size() - j;
        }
        if (j == t.size())
        {
            return s.size() - i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = f(s, t, i + 1, j + 1);
        }

        return dp[i][j] = 1 + min({f(s, t, i, j + 1), f(s, t, i + 1, j), f(s, t, i + 1, j + 1)});
    }

public:
    int minDistance(string s, string t)
    {
        memset(dp, -1, sizeof dp);
        return f(s, t, 0, 0);
    }
};

int main(){
    

    return 0;
}