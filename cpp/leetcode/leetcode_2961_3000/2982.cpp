#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/

class Solution{
public:
    int maximumLength(string s)
    {
        unordered_map<char, int> mp;
        int n = s.size();
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            maxi = max(mp[s[i]], maxi);
        }
        if (maxi <= 2)
            return -1;

        unordered_map<char, vector<int>> occur;
        // string t = s[0];
        char ch = s[0];
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (ch == s[i])
            {
                // t+=s[i];
                count++;
            }
            else
            {
                if (count > 1)
                {
                    occur[ch].push_back(count);
                }
                // t = s[i];
                ch = s[i];
                count = 1;
            }
        }
        if (count > 1)
        {
            occur[ch].push_back(count);
        }

        maxi = 1;
        for (auto it : occur)
        {
            vector<int> &v = it.second;
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                maxi = max(maxi, v[i] - 2);
                if (v.size() - i >= 3)
                {
                    maxi = max(maxi, v[i]);
                }
                if (i + 1 < v.size() and v[i] < v[i + 1])
                {
                    maxi = max(maxi, v[i]);
                }
                if (i + 1 < v.size() and v[i] <= v[i + 1])
                {
                    maxi = max(maxi, v[i] - 1);
                }
            }
        }

        return maxi;
    }
};

class Solution
{

    bool f(int mid, string &s)
    {
        unordered_map<string, int> mp;
        int i = 0, j = max(0, mid - 1);
        vector<string> v;
        while (j < s.size())
        {
            string t = s.substr(i, j - i + 1);
            mp[t]++;
            if (mp[t] > 2)
            {
                v.push_back(t);
            }
            i++, j++;
        }

        for (int i = 0; i < v.size(); i++)
        {
            string &t = v[i];
            char ch = t[0];
            bool flag = true;
            for (int i = 0; i < t.size(); i++)
            {
                if (ch != t[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }
        return false;
    }

public:
    int maximumLength(string s)
    {
        int n = s.size();
        int lo = 0, hi = n;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (f(mid, s))
            {
                ans = max(mid, ans);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};

int main(){
    

    return 0;
}