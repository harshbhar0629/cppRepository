#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-convert-string-ii/

#define ll long long int
class Solution
{
    unordered_map<string, int> label;
    ll dis[205][205];
    ll dp[1005];

    ll f(string &s, string &t, int i)
    {
        int n = s.size();
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        ll result = 1e15;
        if (s[i] == t[i])
        {
            result = min(result, f(s, t, i + 1));
        }

        string src = "", dest = "";
        for (int j = i; j < n; j++)
        {
            src += s[j];
            dest += t[j];
            if (label.find(src) != label.end() and label.find(dest) != label.end())
            {
                int u = label[src];
                int v = label[dest];
                ll conversion = dis[u][v];
                result = min(result, conversion + f(s, t, j + 1));
            }
        }
        return dp[i] = result;
    }

public:
    ll minimumCost(string src, string tar, vector<string> &org, vector<string> &changed, vector<int> &cost)
    {

        int n = cost.size();
        // first creating mapping of every node
        for (int i = 0; i < n; i++)
        {
            label[org[i]] = 0;
            label[changed[i]] = 0;
        }

        // in this case we r assigning a unique id's to all label string
        int total = 0;
        for (auto &it : label)
        {
            it.second = total++;
        }

        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                dis[i][j] = 1e15;
            }
            dis[i][i] = 0;
        }

        // memset(dis, INT_MAX, sizeof dis);
        // we have to assign cost in distance array
        for (int i = 0; i < n; i++)
        {
            int u = label[org[i]];
            int v = label[changed[i]];
            // cout<<u<<" "<<v<<endl;
            dis[u][v] = min(dis[u][v], 1ll * cost[i]);
            // cout<<dis[u][v]<<" ";
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<dis[i][j]<<" ";
        //     }cout<<endl;
        // }

        // apply floyd's warshall
        for (int k = 0; k < total; k++)
        {
            for (int i = 0; i < total; i++)
            {
                for (int j = 0; j < total; j++)
                {
                    if (k != j and i != j and i != k)
                    {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        // cout<<dis[i][j]<<" ";
                    }
                }
                // cout<<endl;
                // dis[i][i] = 0;
            }
        }

        memset(dp, -1, sizeof dp);
        ll ans = f(src, tar, 0);
        return ans >= 1e15 ? -1 : ans;
    }
};

int main(){
    

    return 0;
}