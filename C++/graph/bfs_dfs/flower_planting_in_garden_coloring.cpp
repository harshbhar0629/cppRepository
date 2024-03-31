#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

class Solution {

    void bfs(int n, vector<int>& color, vector<list<int>>& graph){
        
        queue<int>q;
        for(int i=0; i<n; i++){
            
            if(color[i]==-1){
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    for(auto x: graph[curr]){
                        if(color[x] == -1){
                            color[x] = max(1, (color[curr]+1)%5);
                            q.push(x);
                        }
                        else if(color[x] == color[curr]){
                            color[x] = max(1, (color[curr]+1)%5);
                        }
                    }
                }
            }
        }
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       
        vector<list<int>>graph(n);
        vector<int>color(n,-1);

        for(auto x: paths){
            graph[x[0]-1].push_back(x[1]-1);
            graph[x[1]-1].push_back(x[0]-1);
        }
        bfs(n, color, graph);

        return color;
        
    }
};


int main(){
    

    return 0;
}