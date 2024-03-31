#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{
    vector<string> ans;
    bool vis[10][10];
    void f(int r, int c, string &s, int n, vector<vector<int>> &mat)
    {
        if (r == n - 1 and c == n - 1)
        {
            ans.push_back(s);
            return;
        }
        if (mat[r][c] == 0)
        {
            return;
        }

        vis[r][c] = true;

        // going right (c+1)
        if (c + 1 < n and vis[r][c + 1] == false and mat[r][c + 1] == 1)
        {
            s += 'R';
            f(r, c + 1, s, n, mat);
            s.pop_back();
        }

        // going left (c+1)
        if (c - 1 >= 0 and vis[r][c - 1] == false and mat[r][c - 1] == 1)
        {
            s += 'L';
            f(r, c - 1, s, n, mat);
            s.pop_back();
        }

        // going up (r-1)
        if (r - 1 >= 0 and vis[r - 1][c] == false and mat[r - 1][c] == 1)
        {
            s += 'U';
            f(r - 1, c, s, n, mat);
            s.pop_back();
        }
        // cout<<r<<" "<<c<<" "<<vis[r+1][c]<<"\n";
        // going down (r+1)
        if (r + 1 < n and vis[r + 1][c] == false and mat[r + 1][c] == 1)
        {
            s += 'D';
            f(r + 1, c, s, n, mat);
            s.pop_back();
        }

        vis[r][c] = false;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (m[n - 1][n - 1] == 0)
        {
            return {};
        }
        string s = "";
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                vis[i][j] = false;
            }
        }
        f(0, 0, s, n, m);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    

    return 0;
}