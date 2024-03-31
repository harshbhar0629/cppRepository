// https://leetcode.com/problems/min-cost-to-connect-all-points/description/
#include <bits/stdc++.h>
using namespace std;


struct edge{
    int s,d, wt;
};

class Solution {

    vector<int>par;
    // vector<int>rank;

    int find(int x){
        if(par[x] == -1) return x;
        return par[x] = find(par[x]);
    }

    void _union(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        par[a] = b;
        // if(rank[a] >= rank[b]){
        //     rank[a]++;
        //     par[b] = a; 
        // }
        // else{
        //     rank[b]++;
        //     par[a] = b; 
        // }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n = points.size();
        vector<edge> graph;
    
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.push_back({i, j, d});
            }
        }
    
        par.resize(n,-1);
        // rank.resize(n,0);
        sort(graph.begin(), graph.end(), [](edge& e1, edge& e2) {return e1.wt < e2.wt;});
        int cost =0;

        for(auto it: graph){
            // cout<<it.wt<<" ";
            if(find(it.s) != find(it.d)){
                cost += it.wt;
                _union(it.s, it.d);
            }
        }
        return cost;
    }
};

class Solution {
public:

    int manhattanDis(vector<int>&a , vector<int>&b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<bool> vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        priority_queue<int,vector<int>, greater<int>>pq;

        pq.push(0);
        dis[0] = 0;
        int ans = 0 ;
        vis[0] = true;

        while(!pq.empty()){
            auto [u,w] = pq.top();
            pq.pop();
            if(vis[u] || dis[u]<w) continue;
            vis[u] = true;
            ans+=w;
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    int d = manhattanDis(points[i], points[u]);
                    if(dis[i]>d){
                        pq.push({d,i});
                        dis[i] = d;
                    }
                }
            }
        }
        
        return ans;
        
    }
};
// int init = []{
//     ofstream("user.out", ios::out) << "20\n18\n4\n4000000\n0\n53\n102\n85\n139\n113\n97\n94\n109\n123\n143\n136\n157\n165\n131\n104\n112\n119\n101\n126\n135\n123\n93\n120\n138\n140\n124\n144\n152\n149\n1054\n1021\n999\n1064\n997\n1125\n746\n933\n1208\n1044\n22679\n15105\n12392\n24187\n21316\n21129\n20139\n15581\n22867\n14091\n18173\n13616\n21160\n13187\n19252\n17097\n20424\n18951\n20502\n15390\n361721\n322354\n367814\n351638\n273927\n4196509\n4278850\n61998010\n";

//     exit(0);
//     return 0;
// }();

// class Solution{public:int minCostConnectPoints(vector<vector<int>>&points){return 0;}};


int main(){
    
   

    return 0;
}