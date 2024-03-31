#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/number-of-islands/1

class Solution
{
    vector<int> Rank;
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        if (Rank[a] < Rank[b])
        {
            Rank[b]++;
            parent[a] = b;
        }
        else
        {
            Rank[a]++;
            parent[b] = a;
        }
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        parent.resize(n * m, -1);
        Rank.resize(n * m, 1);
        // take visited matrix or you can also take set for visited
        int vis[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
            }
        }

        int cnt = 0;
        vector<int> ans;
        const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto it : operators)
        {
            // fetch (row-col)
            int u = it[0];
            int v = it[1];
            // if already visited means we don't have to check again cnt remains same
            if (vis[u][v])
            {
                ans.push_back(cnt);
                continue;
            }

            // if not visited mark as visited
            vis[u][v] = true;
            // now connected component is inc by one
            cnt++;

            // proceed or check all its adjacent neighbour
            for (int d = 0; d < 4; d++)
            {
                // adjacent neighbour
                int r = u + dir[d].first;
                int c = v + dir[d].second;
                // validation check
                if (r < 0 || c < 0 || r >= n || c >= m)
                {
                    continue;
                }
                // if adjacent neighbour is already visited means we r in same component
                if (vis[r][c] == true)
                {
                    int node = u * m + v;
                    int adjNode = r * m + c;
                    // if current node and adjacent node is not having same parent then connected component decrease by one
                    if (find(node) != find(adjNode))
                    {
                        cnt--;
                        // mark in same connected component and apply Union for it
                        Union(node, adjNode);
                    }
                }
            }
            // whatever count of connected component till now push in our answer
            ans.push_back(cnt);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}