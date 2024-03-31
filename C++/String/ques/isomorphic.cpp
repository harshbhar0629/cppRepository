#include <bits\stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    vector<int> vt(150, 200);
    vector<int> v(150, 200);

    for (int i = 0; i < s.size(); i++)
    {
        if (vt[s[i]] != v[t[i]])
            return false;
        vt[s[i]] = i + 1;
        v[t[i]] = i + 1;
    }
    return true;
}

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    vector<int> v(150, 200);

    for (int i = 0; i < s.size(); i++)
    {
        int idx = (int)s[i];
        if (v[idx] == 200)
        {
            v[idx] = s[i] - t[i];
        }
        else if (v[idx] != s[i] - t[i])
        {
            return false;
        }
    }
    vector<int> vt(150, 200);

    for (int i = 0; i < t.size(); i++)
    {
        int idx = (int)t[i];
        if (vt[idx] == 200)
        {
            vt[idx] = t[i] - s[i];
        }
        else if (v[idx] != t[i] - s[i])
        {
            return false;
        }
    }
    return true;
}