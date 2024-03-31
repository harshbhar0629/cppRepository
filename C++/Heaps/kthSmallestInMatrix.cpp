#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
        int n = matrix.size();

        for (int i = 0; i < min(n, k); i++)
        {
            pq.push({matrix[i][0], {i, 0}});
        }

        pair<int, pair<int, int>> p;

        while (k-- and not pq.empty())
        {
            p = pq.top();
            pq.pop();
            int data = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if (col + 1 < matrix[row].size())
            {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
        }
        return p.first;
    }
};

class Solution
{
public:
    // TC: O(log(m+n)*(nlogn))
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int lo = mat[0][0];
        int hi = mat[n - 1][n - 1];
        int cnt = 0;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            cnt = 0;
            for (int i = 0; i < n; i++)
            {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};

class Solution
{

    int cnt_smaller_ele(vector<vector<int>> &mat, int mid)
    {
        int n = mat.size();
        int j = n - 1, i = 0;
        int cnt = 0;

        while (i < n and j >= 0)
        {
            if (mat[i][j] <= mid)
            {
                cnt += j + 1;
                i++;
            }
            else
            {
                j--;
            }
        }

        return cnt;
    }

public:
    // TC: O(log(n+n)(n+n))
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int lo = mat[0][0];
        int hi = mat[n - 1][n - 1];

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            // int cnt = 0;
            // for(int i=0; i<n; i++){
            //     cnt+= upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            // }
            int cnt = cnt_smaller_ele(mat, mid);
            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};

int main()
{

    return 0;
}