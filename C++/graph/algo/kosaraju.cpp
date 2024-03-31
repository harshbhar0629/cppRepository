#include <bits/stdc++.h>
using namespace std;
/**
 * https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
 * Steps to solve kosaraju algo
 * it is only valid for DAG
 * step-1
 * sort all edges on their finishing time - TOPO SORT
 * step-2
 * transpose of graph -> reverse all edges
 * step-3
 * DFS apply and cnt strongly connected component
 *
 */

class Solution
{
    void dfs(int src, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[src] = true;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(src);
    }

    void dfs1(int src, vector<bool> &vis, unordered_map<int, list<int>> &mp)
    {
        vis[src] = true;
        for (auto nbr : mp[src])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, vis, mp);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>> &adj){
        // given adj mat if not given then create graph
        // sort all edges on their respective finishing time
        stack<int> st;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        // now reverse all edges
        unordered_map<int, list<int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                mp[it].push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }

        // count connected component apply dfs for all those how are not previously visited
        int SCC = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (!vis[top])
            {
                SCC++;
                dfs1(top, vis, mp);
            }
        }

        return SCC;
    }
};

int main(){
    

    return 0;
}