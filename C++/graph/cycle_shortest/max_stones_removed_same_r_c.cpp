// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    void dfs(vector<vector<int>>& stones, int idx, vector<bool>& visited){
        visited[idx] = true;
        for(int i=0; i<stones.size(); i++){
            if(!visited[i] and (stones[i][0]==stones[idx][0] || stones[i][1]==stones[idx][1])){
                dfs(stones, i, visited);
            }
        }

    }

public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<bool>visited(n,0);
        int groups=0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(stones, i, visited);
                groups++;
            }
        }
        return n - groups;
    }
};


int main(){
    

    return 0;
}