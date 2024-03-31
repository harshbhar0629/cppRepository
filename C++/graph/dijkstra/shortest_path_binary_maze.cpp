#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
class Solution
{
    using pi = pair<int, int>;
    using ppi = pair<int, pi>;

public:
    int shortestPath(vector<vector<int>> &grid, pi src, pi dest)
    {
        if (grid[src.f][src.s] == 0 || grid[dest.f][dest.s] == 0)
        {
            return -1;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e8));
        vector<pi> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({0, src});
        dis[src.f][src.s] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int dist = curr.f;
            int row = curr.s.f;
            int col = curr.s.s;

            for (int d = 0; d < 4; d++)
            {
                int nr = row + dir[d].f;
                int nc = col + dir[d].s;
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] != 1)
                {
                    continue;
                }
                grid[nr][nc] = 2;
                if (dis[nr][nc] > dis[row][col] + 1)
                {
                    dis[nr][nc] = dis[row][col] + 1;
                    pq.push({dis[nr][nc], {nr, nc}});
                }
            }
        }
        if (dis[dest.f][dest.s] == 1e8)
        {
            return -1;
        }
        return dis[dest.f][dest.s];
    }
};



int main(){
    

    return 0;
}