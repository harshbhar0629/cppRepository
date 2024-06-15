#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindromic-substrings/description

class Solution
{

    int dp[1005];
    bool isPalindrome(const string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }

        return true;
    }

    int f(const string &s, int i)
    {
        if (i == s.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int exc = f(s, i + 1);
        int inc = 0;

        for (int idx = i; idx < s.size(); idx++)
        {
            if (isPalindrome(s, i, idx))
            {
                inc++;
            }
        }

        return dp[i] = inc + exc;
    }

public:
    int countSubstrings(string s)
    {
        memset(dp, -1, sizeof dp);
        return f(s, 0);
    }
};

int main(){
    

    return 0;
}