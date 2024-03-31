#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/find-missing-and-repeated-values/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> ans;
        vector<bool> vis(3000, 0);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[grid[i][j]]++;
                if (mp[grid[i][j]] > 1)
                {
                    ans.push_back(grid[i][j]);
                }
                vis[grid[i][j]] = 1;
            }
        }

        for (int i = 1; i < 3000; i++)
        {
            if (!vis[i])
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}