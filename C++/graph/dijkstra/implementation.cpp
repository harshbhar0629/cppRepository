/**
 * construct graph
 * DS -> priority_queue(pair(dis, node)), distance arr, visited(bool), via->parents 
 * pop root of pq and check if yet visited or not if yes then continue o/w mark as visited
 * go to its neighbour and push in pq
 * and also check its distance if dis is greater then curr via distance then update 
 * try to backtrack dis arr and also store wt at every time 
*/


#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

vector<list<pp>> graph;
int v;

void add_edge(int s, int d, int wt){
    graph[s].push_back({d,wt});
    graph[d].push_back({s,wt});
}

// TC: O(VlogV + ElogV) = O(ElogV)
vector<int> shortest_dis_with_min_weight(int src){

    priority_queue<pp, vector<pp> , greater<pp>> pq;
    vector<bool> vis(v+1, 0);
    vector<int>dis(v+1, INT_MAX) ,via(v+1, -1);

    via[src] = src;
    dis[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        auto curr = pq.top(); // (dis, node)
        pq.pop();
        if(vis[curr.second]) continue;

        vis[curr.second] = true;

        for(auto it: graph[curr.second]){
            if(!vis[it.first] and dis[curr.second] + it.second < dis[it.first] ){
                pq.push({dis[curr.second] + it.second, it.first});
                dis[it.first] = dis[curr.second] + it.second;
                via[it.first] = curr.second;
            }
        }
    }
    return dis;
}
// 7 9
// 0 1 1
// 0 2 5
// 1 2 4
// 1 3 1
// 3 4 1
// 2 4 1
// 3 6 2 
// 6 5 1
// 4 5 5
// 0
// 0 -> 0
// 1 -> 1
// 2 -> 4
// 3 -> 2
// 4 -> 3
// 5 -> 5
// 6 -> 4

int main(){
    
    cin>>v;
    graph.resize(v+1, list<pp>());

    int e;
    cin>>e;

    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s, d, wt);
    }

    int s,d;
    cin>>s;

    vector<int> dis = shortest_dis_with_min_weight(s);

    for(int i=0; i<v; i++){
        cout<<i<<" -> "<<dis[i]<<"\n";
    }

    return 0;
}
// memset(dist, 1e8, sizeof dist);//neighbour wt//valid case//neighbour// curr wt// curr idx