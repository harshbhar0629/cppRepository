#include <bits/stdc++.h>
using namespace std;

int v;
vector<list<int>>graph;

// bi directional
void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Edge done\n";
}

unordered_set<int>visited;
void bfs(int s ,vector<int>&dis){

    visited.clear();
    queue<int>qu;
    visited.insert(s);
    dis.resize(v, INT_MAX);
    dis[s] = 0;
    qu.push(s);

    while(not qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(not visited.count(neighbour)){
                dis[neighbour] = dis[curr] + 1;
                qu.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}


int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }

    int s;
    cin>>s;

    vector<int> dis;
    // shortest path
    bfs(s, dis);

    for(auto ele : dis){
        cout<<ele<<" ";
    }

    return 0;
}