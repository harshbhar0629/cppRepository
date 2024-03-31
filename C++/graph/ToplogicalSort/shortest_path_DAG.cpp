#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution
{
    using pi = pair<int, int>;
    void topo(int src, stack<int> &st, vector<bool> &vis, vector<pi> adj[])
    {
        vis[src] = true;
        for (auto it : adj[src])
        {
            if (!vis[it.first])
            {
                topo(it.first, st, vis, adj);
            }
        }
        st.push(src);
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pi> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        vector<bool> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topo(i, st, vis, adj);
            }
        }

        vector<int> dis(n, 1e7);
        dis[0] = 0;

        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();

            for (auto it : adj[curr])
            {
                if (dis[it.first] > dis[curr] + it.second)
                {
                    dis[it.first] = dis[curr] + it.second;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dis[i] == 1e7)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};

int main(){
    

    return 0;
}