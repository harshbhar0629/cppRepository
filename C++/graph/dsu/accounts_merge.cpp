#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/accounts-merge/description/

class Solution
{
    vector<int> par, rank;
    int find(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }

        if (rank[b] <= rank[a])
        {
            rank[a]++;
            par[b] = a;
        }
        else
        {
            par[a] = b;
            rank[b]++;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc)
    {
        int n = acc.size();
        unordered_map<string, int> mp;
        par.resize(n, -1);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < acc[i].size(); j++)
            {
                string s = acc[i][j];
                if (mp.find(s) != mp.end())
                {
                    int a = mp[s];
                    int b = i;
                    Union(a, b);
                }
                else
                {
                    mp[s] = i;
                }
            }
        }

        vector<string> adj[n];
        for (auto it : mp)
        {
            int idx = find(it.second);
            adj[idx].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0)
            {
                continue;
            }

            sort(adj[i].begin(), adj[i].end());
            vector<string> temp;
            temp.emplace_back(acc[i][0]);

            for (auto it : adj[i])
            {
                temp.emplace_back(it);
            }
            ans.emplace_back(temp);
        }

        return ans;
    }
};

int main(){
    vector<int> v;
    cout << typeid(v).name();

    return 0;
}