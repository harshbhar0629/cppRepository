#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-paths-iii/

class Solution
{

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int f(int i, int j, int steps, const pair<int, int> &dest, vector<vector<int>> &grid)
    {
        if (steps == -1 and pair<int, int>(i, j) == dest)
        {
            return 1;
        }
        if (grid[i][j] == -1)
        {
            return 0;
        }

        // mark as visited
        grid[i][j] = -1;

        int ans = 0;
        for (int d = 0; d < 4; d++)
        {
            int ni = dx[d] + i;
            int nj = dy[d] + j;
            if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] == -1)
            {
                continue;
            }
            ans += f(ni, nj, steps - 1, dest, grid);
        }

        // mark as unvisited
        grid[i][j] = 0;
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int empty = 0;
        pair<int, int> dest;
        pair<int, int> src;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    src = {i, j};
                }
                if (grid[i][j] == 2)
                {
                    dest = {i, j};
                }
                if (grid[i][j] == 0)
                {
                    empty++;
                }
            }
        }

        return f(src.first, src.second, empty, dest, grid);
    }


    int uniquePath3(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int empty = 0;
        pair<int, int> dest, src;

        for (int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    src = {i, j};
                }            
                if(grid[i][j] == 2){
                    dest = {i, j};
                }
                if(grid[i][j] == 0){
                    empty++;
                }
            }
        }

        return f1(src.first, src.second, empty, dest, grid);
    }

    int f1(int i, int j, int steps, const pair<int,int>& dest, vector<vector<int>>& grid){
        if(steps == -1 and pair<int,int>(i,j) == dest){
            return 1;
        }
        //check this is already visited before or not
        if(grid[i][j] == -1){
            return 0;
        }

        //mark as visited
        grid[i][j] = -1;

        int ans = 0;
        for (int d = 0; d < 4; d++){
            int newRow = i + dx[d];
            int newCol = j + dy[d];
            if(newCol < 0 || newRow < 0 || newCol >= grid[0].size() || newRow >= grid.size() || grid[newRow][newCol] == -1){
                continue;
            }

            ans += f(newRow, newCol, steps - 1, dest, grid);
        }

        grid[i][j] = 0;
        return ans;
    }
};

int main(){
    

    return 0;
}