#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution
{
    using pi = pair<int, int>;

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pi> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        vector<int> dis(n, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        vector<bool> vis(n, 0);
        dis[0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            if (vis[curr.second])
            {
                continue;
            }
            vis[curr.second] = true;
            for (auto it : adj[curr.second])
            {
                if (!vis[it.first] and dis[it.first] > curr.first + it.second)
                {
                    dis[it.first] = curr.first + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};

class Solution
{
    using pi = pair<int, int>;

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pi> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        vector<int> dis(n, INT_MAX);
        queue<pi> pq;
        pq.push({0, 0});
        // vector<bool>vis(n, 0);
        dis[0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.front();
            pq.pop();
            // if(vis[curr.second]){
            // continue;
            // }
            // vis[curr.second] = true;
            for (auto it : adj[curr.second])
            {
                if (dis[it.first] > curr.first + it.second)
                {
                    dis[it.first] = curr.first + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
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