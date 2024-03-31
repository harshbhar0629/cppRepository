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



bool bfs(int src, int parent){
    queue<pair<int,int>>q;
    q.push({src, parent});
    visited.insert(src);

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int node = curr.first;
        int parent = curr.second;
        for(auto it: graph[node]){
            if(!visited.count(it)){
                visited.insert(it);
                q.push({it, node});
            }
            else if(it!=parent){
                return true;
            }
        }
    }
    return false;
}



bool has_cycle(){
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            bool b = bfs(i,-1);
            if(b) return true;
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
    else{
        cout<<"No cycle\n";
    }

    return 0;
}