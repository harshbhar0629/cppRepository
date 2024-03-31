#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/

// similar 2982
class Solution
{

    bool isSafe(string &t)
    {
        if (t.size() <= 1)
            return true;
        char ch = t[0];
        for (int i = 0; i < t.size(); i++)
        {
            if (ch != t[i])
                return false;
        }
        return true;
    }

public:
    int maximumLength(string s)
    {
        int maxi = 0;
        int n = s.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            maxi = max(mp[s[i]], maxi);
        }

        if (maxi <= 2)
            return -1;
        unordered_map<string, int> mapping;
        // generate all possible substring and any sybstring appear 3 time then we will check this substring all characters are same or not if yes then it is a specail substring
        maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string t = s.substr(i, j - i + 1);
                // cout<<t<<" ";
                mapping[t]++;
                if (mapping[t] >= 3 and isSafe(t))
                {
                    int _n = t.size();
                    maxi = max(maxi, _n);
                }
            }
        }
        return maxi;
    }
};

int main(){
    

    return 0;
}