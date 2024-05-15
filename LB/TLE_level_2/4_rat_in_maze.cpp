#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
//  sorted paths mean that the expected output should be in alphabetical order.

void f(int i, int j, string s, vector<string> &ans, vector<vector<int>> &vis, vector<vector<int>> &arr, int n)
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(s);
    return;
  }

  // down
  if (i + 1 < n && !vis[i + 1][j] && arr[i + 1][j] == 1)
  {
    vis[i][j] = 1;
    f(i + 1, j, s + 'D', ans, vis, arr, n);
    vis[i][j] = 0;
  }

  // left
  if (j - 1 >= 0 && !vis[i][j - 1] && arr[i][j - 1] == 1)
  {
    vis[i][j] = 1;
    f(i, j - 1, s + 'L', ans, vis, arr, n);
    vis[i][j] = 0;
  }

  // right
  if (j + 1 < n && !vis[i][j + 1] && arr[i][j + 1] == 1)
  {
    vis[i][j] = 1;
    f(i, j + 1, s + 'R', ans, vis, arr, n);
    vis[i][j] = 0;
  }

  // upward
  if (i - 1 >= 0 && !vis[i - 1][j] && arr[i - 1][j] == 1)
  {
    vis[i][j] = 1;
    f(i - 1, j, s + 'U', ans, vis, arr, n);
    vis[i][j] = 0;
  }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  if (arr[0][0] == 1)
  {
    f(0, 0, "", ans, vis, arr, n);
  }
  return ans;
}

class Solution
{
  int vis[10][10];
  string direction = "LRUD";
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  vector<string> ans;

  void f(vector<vector<int>> &m, string &s, int r, int c, const int n)
  {

    if (r == n - 1 and c == n - 1)
    {
      ans.push_back(s);
      return;
    }
    vis[r][c] = 1;
    for (int d = 0; d < 4; d++)
    {
      int nr = r + dy[d];
      int nc = c + dx[d];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n || m[nr][nc] == 0 || vis[nr][nc] != -1)
      {
        continue;
      }

      s += direction[d];
      f(m, s, nr, nc, n);

      s.pop_back();
      // vis[nr][nc] = -1;
    }
    vis[r][c] = -1;
  }

public:
  vector<string> findPath(vector<vector<int>> &m, int n)
  {
    if (m[n - 1][n - 1] == 0 || m[0][0] == 0)
    {
      return {};
    }

    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        vis[i][j] = -1;
      }
    }
    string s = "";
    f(m, s, 0, 0, n);

    return ans;
  }
};

int main()
{

  return 0;
}