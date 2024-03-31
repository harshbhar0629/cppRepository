#include <bits/stdc++.h>
using namespace std;
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

int main()
{

  return 0;
}