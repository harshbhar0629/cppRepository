#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/description/


#define ll long long int
class Solution{

    void f(int src, vector<list<int>>&graph, vector<int>pos_val[], vector<int>neg_val[], vector<int>&subtree, vector<bool>& visited, vector<int>&cost, vector<ll>& ans){
        visited[src] = true;
        if(cost[src] < 0){
            neg_val[src].push_back(cost[src]);
        }
        else{
            pos_val[src].push_back(cost[src]);
        }

        for(auto node: graph[src]){
            if(!visited[node]){
                f(node, graph, pos_val, neg_val, subtree, visited, cost,ans);
                subtree[src] += subtree[node];
              
                for(auto it: pos_val[node]){
                    pos_val[src].push_back(it);
                }
                for(auto it: neg_val[src]){
                    neg_val[src].push_back(it);
                }
            }
        }

        if(subtree[src] < 3){
            ans[src] = 1;
        }
        else {
            sort(pos_val[src].begin(), pos_val[src].end(), greater<int>());
            if(pos_val[src].size() >= 3){
                ans[src] = 1ll * pos_val[src][0] * pos_val[src][1] * pos_val[src][2];
                pos_val[src].resize(3);
            }
            if(neg_val[src].size() >=2 and pos_val[src].size() > 0){
                ans[src] = max(ans[src], 1ll * pos_val[src][0] * neg_val[src][0] * neg_val[src][1]);
                neg_val[src].resize(2);
            }
        }
    }

public:
    vector<ll> placedCoins(vector<vector<int>> &edges, vector<int> &cost){
        
        int n = cost.size();
        vector<list < int >> graph(n, list<int>());
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> pos_val[n];
        vector<int> neg_val[n];
        vector<bool> visited(n, 0);
        vector<int> subtree(n, 1);
        vector<ll> ans(n);
        f(0, graph, pos_val, neg_val, subtree, visited, cost, ans);

        return ans;
    }
};

#define ll long long int
class Solution
{

    void f(int src, vector<list<int>> &graph, vector<int> pos_val[], vector<int> neg_val[], vector<bool> &visited, vector<int> &cost, vector<ll> &ans){
        visited[src] = true;
        if (cost[src] < 0){
            neg_val[src].push_back(cost[src]);
        }
        else{
            pos_val[src].push_back(cost[src]);
        }

        for (auto node : graph[src]){
            if (!visited[node]){
                f(node, graph, pos_val, neg_val, visited, cost, ans);

                for (auto it : pos_val[node]){
                    pos_val[src].push_back(it);
                }
                for (auto it : neg_val[src]){
                    neg_val[src].push_back(it);
                }
            }
        }

        if (pos_val[src].size() + neg_val[src].size() < 3){
            ans[src] = 1;
        }
        else{
            sort(pos_val[src].begin(), pos_val[src].end(), greater<int>());
            if (pos_val[src].size() >= 3){
                ans[src] = 1ll * pos_val[src][0] * pos_val[src][1] * pos_val[src][2];
                pos_val[src].resize(3);
            }
            if (neg_val[src].size() >= 2 and pos_val[src].size() > 0){
                ans[src] = max(ans[src], 1ll * pos_val[src][0] * neg_val[src][0] * neg_val[src][1]);
                neg_val[src].resize(2);
            }
        }
    }

public:
    vector<ll> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
    {

        int n = cost.size();
        vector<list<int>> graph(n, list<int>());
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> pos_val[n];
        vector<int> neg_val[n];
        vector<bool> visited(n, 0);
        vector<ll> ans(n);
        f(0, graph, pos_val, neg_val, visited, cost, ans);

        return ans;
    }
};

int main(){
    

    return 0;
}