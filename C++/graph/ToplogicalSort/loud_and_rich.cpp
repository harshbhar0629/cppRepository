#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/loud-and-rich/


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // we will store all incoming edges
        int n = quiet.size();
        vector<int>ans(n);
        vector<list<int>>graph(n);
        vector<int>indeg(n,0);

        for(auto x: richer){
            graph[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }

        queue<int>qu;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                qu.push(i);
            }
            ans[i] = i;
        }

        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();

            for(auto x: graph[curr]){
                if(--indeg[x]==0) qu.push(x);
                // if incoming edge has lesser quietness level from its parent
                if(quiet[ans[x]] > quiet[ans[curr]]){
                    ans[x] = ans[curr];
                }
            }
        }
        return ans;
    }
};


int main(){
    

    return 0;
}