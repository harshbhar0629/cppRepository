#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

#define ll long long int
class Solution
{

    vector<vector<ll>> graph;
    void floyd_warshall(vector<char> &org, vector<char> &changed, vector<int> &cost)
    {
        for (int i = 0; i < org.size(); i++)
        {
            int s = org[i] - 'a';
            int t = changed[i] - 'a';
            graph[s][t] = min(graph[s][t], (ll)cost[i]);
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

public:
    ll minimumCost(string src, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        graph.resize(26, vector<ll>(26, 1e9));
        floyd_warshall(original, changed, cost);

        ll total_cost = 0;

        for (int i = 0; i < src.size(); i++)
        {
            int s = src[i] - 'a';
            int t = target[i] - 'a';
            if (s == t)
                continue;
            if (graph[s][t] == 1e9)
                return -1;
            total_cost += graph[s][t];
        }

        return total_cost;
    }
};

#define ll long long int
#define pp pair<char, int>
#define p pair<int, char>
class Solution
{

    void dijkstra(char src, unordered_map<char, vector<pp>> &mp, vector<vector<ll>> &cost)
    {
        // cost[src-'a'][src-'a'] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});

        // while (!pq.empty())
        // {
        //     auto [wt, curr] = pq.top();
        //     pq.pop();
        //     for (auto [node, edge_wt] : mp[curr])
        //     {
        //         if (cost[src - 'a'][node - 'a'] > edge_wt + wt)
        //         {
        //             cost[src - 'a'][node - 'a'] = edge_wt + wt;
        //             pq.push({edge_wt + wt, node});
        //         }
        //     }
        // }
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {

        unordered_map<char, vector<pair<char, int>>> mp;
        for (int i = 0; i < original.size(); i++)
        {
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<ll>> costMatrix(26, vector<ll>(26, INT_MAX));

        for (int i = 0; i < 26; i++)
        {
            dijkstra(i + 'a', mp, costMatrix);
        }

        ll total_cost = 0;

        for (int i = 0; i < source.size(); i++)
        {
            char s = source[i];
            char t = target[i];
            if (s == t)
                continue;
            if (costMatrix[s - 'a'][t - 'a'] == INT_MAX)
                return -1;
            total_cost += costMatrix[s - 'a'][t - 'a'];
        }
        return total_cost;
    }
};

int main(){
    

    return 0;
}