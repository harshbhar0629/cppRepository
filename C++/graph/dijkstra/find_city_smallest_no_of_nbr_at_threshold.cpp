#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#define pi pair<int,int>
class Solution{

    vector<list<pi>>graph;
    int n;
    int threshold;
    int city, neighbour;

    void dijkstra1(int src){
        vector<int>dis(n, 1e8);
        dis[src] = 0;
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        pq.push({0, src});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;

            for(auto it: graph[node]){
                int edW = it.second;
                int adjN = it.first;

                if(wt + edW < dis[adjN]){
                    dis[adjN] = wt + edW;
                    pq.push({dis[adjN], adjN});
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(dis[i] <= threshold){
                cnt++;
            }
        }

        if(cnt <= neighbour){
            neighbour = cnt;
            city = max(city, src);
        }
    }

    void dijkstra2(int src)
    {
        vector<int> dis(n, 1e8);
        dis[src] = 0;
        queue<pi> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto curr = pq.front();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;

            for (auto it : graph[node])
            {
                int edW = it.second;
                int adjN = it.first;

                if (wt + edW < dis[adjN])
                {
                    dis[adjN] = wt + edW;
                    pq.push({dis[adjN], adjN});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] <= threshold)
            {
                cnt++;
            }
        }

        if (cnt <= neighbour)
        {
            neighbour = cnt;
            city = max(city, src);
        }
    }

    int solve(int n, vector<vector<int>>& edges, int distanceThreshold){
        this->threshold = distanceThreshold;
        this->n = n;
        city = 0 , neighbour = n+1;
        graph.resize(n, list<pi>());

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].emplace_back(v, wt);
            graph[v].emplace_back(u, wt);
        }

        for(int i=0; i<n; i++){
            // cout<<i<<" ";
            dijkstra1(i);
        }

        return city;
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dis(n, vector<int>(n, 1e8));
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dis[u][v] = dis[v][u] = wt;
        }

        for (int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }

        int city = 0, maxi = n + 2;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= maxi)
            {
                maxi = cnt;
                city = i;
            }
        }

        return city;
    }
};

int main(){
    

    return 0;
}