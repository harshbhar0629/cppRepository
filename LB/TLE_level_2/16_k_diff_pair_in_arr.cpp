#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

int f(vector<int> &v, int k)
{
    int n = v.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    int cnt = 0;
    if (k == 0)
    {
        for (auto it : mp)
        {
            if (it.second >= 2)
            {
                cnt++;
            }
        }
    }
    else
    {
        for (auto it : mp)
        {
            int ele = it.first + k;
            if (mp.count(ele) > 0){
                cnt++;
            } 
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;

    cout << f(v, k);
}