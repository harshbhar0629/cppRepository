// https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define pp pair<int,int>


class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int n ,int k){
        vector<pp>adj[n+1];

        for(const vector<int>& it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<int>dis(n+1,INT_MAX);

        dis[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                if(it.second + wt < dis[it.first]){
                    dis[it.first] = it.second + wt;
                    pq.push({it.second + wt, it.first});
                }
            }
        }

        int maxi =0;

        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX) return -1;
            maxi = max(maxi, dis[i]);
        }
        
        return maxi;
    }
};


int main(){
    

    return 0;
}