#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int n, vector<vector<int>> &edges, int src)
    {
        vector<int> dis(n, 1e8);
        dis[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dis[u] != 1e8 and dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dis[u] != 1e8 and dis[u] + wt < dis[v])
            {
                return {-1};
            }
        }

        return dis;
    }
};

int main(){
    

    return 0;
}