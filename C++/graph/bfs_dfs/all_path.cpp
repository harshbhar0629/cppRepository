#include <bits/stdc++.h>
using namespace std;


// TC:(v+e)
int v;
unordered_set<int>visited;
vector<list<int>>graph;
vector<vector<int>>ans;

void add_edge(int s, int d, bool bi_dir=true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Add Edge done\n";
}


void dfs(int curr, int end, vector<int> v){
    if(curr==end) {
        v.push_back(curr);
        ans.push_back(v);
        v.pop_back();
        return;
    }

    visited.insert(curr);
    v.push_back(curr);

    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour, end, v);
        }
    }
    visited.erase(curr);
    v.pop_back();
    return ;
}


void allPath(int src , int dest){
    dfs(src, dest, {});
     
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }cout<<"\n";
    }
    return;
}

// 16 17
// 0 1
// 0 2 
// 2 3 
// 3 4 
// 3 5 
// 1 3
// 1 6 
// 6 9 
// 6 8 
// 8 10 
// 10 7 
// 9 7 
// 9 11 
// 11 12 
// 11 13 
// 13 14 
// 13 15


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

    int x , y;
    cin>>x>>y;

    allPath(x, y);
   

    return 0;
}