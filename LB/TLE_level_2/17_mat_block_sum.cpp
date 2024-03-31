#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> f(vector<vector<int>>& mat, int n, int m, int k){
    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int l = max(0, i - k); l <= min(i + k, n-1); l++){
                for (int r = max(0, j - k); r <= min(m-1, j + k); r++){
                    a[i][j] += mat[l][r];
                }
            }
        }
    }

    return a;
}


class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            }
        }

        for (int i = 1; i < 1 + n; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                int a = max(1, i - k);
                int b = max(1, j - k);
                int c = min(n, i + k);
                int d = min(m, j + k);
                mat[i - 1][j - 1] = dp[c][d] + dp[a - 1][b - 1] - dp[c][b - 1] - dp[a - 1][d];
            }
        }
        return mat;
    }
};


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;

    vector<vector<int>> mat = f(a, n, m, k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
}