#include <bits/stdc++.h>
using namespace std;


// TC:(v+e)
int v;
unordered_set<int>visited;
vector<list<int>>graph;

void add_edge(int s, int d, bool bi_dir=true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Add Edge done\n";
}


bool dfs(int src, int parent){
    visited.insert(src);
    for(auto it: graph[src]){
        if(!visited.count(it) and dfs(it, src)){
            return true;
        }
        else if(it!=parent) return  true;
    }
    return false;
}


bool has_cycle(){
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            bool result = dfs(i, -1);
            if(result) return true;
        }
    }
    return false;
}


int main(){

    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }

    bool result = has_cycle();
    if(result) cout<<"detect cycle\n";

    return 0;
}