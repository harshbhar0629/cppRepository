#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#define ll long long int
class Solution
{
    const ll mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, ll>> adj[n];
        for (auto road : roads)
        {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        vector<ll> dis(n, 1e14), ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            ll wt = curr.first;
            int node = curr.second;
            cout << wt << " ";
            for (auto it : adj[node])
            {
                // if(it.first == n-1){
                //     cout<<"Hello: ";
                // }
                if (it.second + wt < dis[it.first])
                {
                    dis[it.first] = wt + it.second;
                    pq.push({dis[it.first], it.first});
                    ways[it.first] = ways[node];
                }
                else if (it.second + wt == dis[it.first])
                {
                    ways[it.first] += ways[node];
                    ways[it.first] %= mod;
                }
            }
        }
        // cout<<ways[n-1]<<" ";
        // cout<<adj[n-1].size();
        return ways[n - 1] % mod;
    }
};

int main(){
    

    return 0;
}