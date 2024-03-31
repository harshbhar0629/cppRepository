#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#define f first 
#define s second 
#define p pair<int,int>
#define pp pair<int, pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<list<p>>graph(n);
        for(auto& it: flights){
            graph[it[0]].push_back({it[1], it[2]});
        }
    
        vector<int>dis(n,1e9);
        queue<pp>q;
        //store-> stops, node, wt
        q.push({0, {src, 0}});
        dis[src] = 0;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int stops = curr.f;
            int node = curr.s.f;
            int wt = curr.s.s;
            if(stops>k) continue;

            for(auto& it: graph[node]){
                //it->store node wt
                if(wt + it.s < dis[it.f] and stops<=k){
                    dis[it.f] = wt + it.s;
                    q.push({1+stops, {it.f, dis[it.f]}});
                }
            }
        }

        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};


#define f first 
#define s second 
#define p pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<list<p>>graph(n);
        for(auto& it: flights){
            graph[it[0]].push_back({it[1], it[2]});
        }
    
        queue<p>q;
        q.push({src, 0});
        int srcToDst = INT_MAX;
        
        while(!q.empty() and k-->=0){
            int s = q.size();
            for(int i=0; i<s; i++){
                auto curr = q.front();
                q.pop();
                int node = curr.f;
                int wt = curr.s;

                for(auto& it: graph[node]){
                    if(wt+it.s < srcToDst){
                        q.push({it.f, it.second+wt});
                    }
                    if(it.first == dst){
                        srcToDst = min(srcToDst, it.second+wt);
                    }
                }
            }
        }
        return srcToDst == INT_MAX ? -1: srcToDst;
    }
};



int main(){
    

    return 0;
}