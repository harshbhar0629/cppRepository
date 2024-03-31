#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e8;
                }
            }
            matrix[i][i] = 0;
        }

        // floyd's warshall
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e8)
                {
                    matrix[i][j] = -1;
                }
            }
            matrix[i][i] = 0;
        }
    }
};

int main()
{

    return 0;
}