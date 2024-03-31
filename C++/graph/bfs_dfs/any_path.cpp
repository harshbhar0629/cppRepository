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


bool dfs(int curr, int end){
    // cout<<curr<<" ->";
    if(curr==end) return true;
    visited.insert(curr);

    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, end);
            // cout<<result<<"\n";
            if(result) return result;
            cout<<endl;
        }
    }
    // cout<<endl;
    return false;
}


bool anyPath(int src , int dest){
    return dfs(src, dest);
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
// 0 1
// 0 4
// 1 5
// 1 3
// 4 3
// 5 6
// 6 2
// 5 2
// 0 2

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
    cout<<"\nAns->"<<anyPath(x, y);

    return 0;
}