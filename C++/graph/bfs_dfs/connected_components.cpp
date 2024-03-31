#include <bits/stdc++.h>
using namespace std;


unordered_set<int>visited;
vector<list<int>>graph;
int v;

void add_edge(int s, int d, bool bi_dir=true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Add Edge Done\n";
}


void dfs(int curr){
    visited.insert(curr);

    for(auto it: graph[curr]){
        if(not visited.count(it)){
            dfs(it);
        }
    }
}


int connectedComponents(){
    int count=0;
    for(int i=0; i<v; i++){
        if(not visited.count(i)){
            count++;
            dfs(i);
        }
    }
    return count;
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

    cout<<connectedComponents();

    return 0;
}