#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/making-a-large-island/description/

class Solution{
    vector<int> parent, size;
    const vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b){
            return;
        }
        if(size[b] <= size[a]){
            size[a] += size[b];
            parent[b] = a;
        }
        else{
            size[b] += size[a];
            parent[a] = b;
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        // whole grid convert into a single array
        parent.resize(n * m, -1);
        size.resize(n * m, 1);

        for (int i = 0; i<n; i++){
            for (int j = 0; j < m; j++){
                // grid[i][j] == 1 means having a connected component now find its size by using their adjacent cell
                if(grid[i][j] == 1){
                    for (int d = 0; d < 4; d++){
                        // finding adjacent neighbour
                        int row = i + dir[d].first;
                        int col = j + dir[d].second;
                        // check validation
                        if(row<0 || col<0 || row>=n || col>=m || grid[row][col] != 1){
                            continue;
                        }
                        // apply union for curr_node and adjNode
                        int node = i * m + j;
                        int adjNode = row * m + col;
                        Union(node, adjNode);
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                // if we encounter on grid[i][j] == 0 that means it might be possibility ki it have island to its neighbour now check its adjacent
                if(grid[i][j] == 0){
                    // for uniquely identify to its neighbour parent
                    unordered_set<int> st;
                    for (int d = 0; d < 4; d++){
                        // adjacent neighbour
                        int row = i + dir[d].first;
                        int col = j + dir[d].second;
                        // check validation
                        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != 1){
                            continue;
                        }
                        // find parent of adjNode and insert into set DS bcoz it have island 
                        int node = row * m + col;
                        st.insert(find(node));
                    }
                    // now finding overall count of size of their adjacent
                    int cnt = 0;
                    for(auto it: st){
                        cnt += size[it];
                    }
                    // finding maximum (one+) bcoz we have choice to flip one 0->1
                    maxi = max(cnt+1, maxi);
                }
            }
        }
        // suppose if we have all ele in grid == 1 then that case find overall maximum
        for (int i = 0; i<n*m; i++){
            maxi = max(maxi, size[i]);
        }
        return maxi;
    }
};

int main(){
    

    return 0;
}