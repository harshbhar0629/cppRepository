#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<bool,int>>> graph;
int v;

void add_edge(int s, int d,int wt, bool bi_dir=true){
    graph[s][d].first = bi_dir;
    graph[s][d].second = wt;
    if(bi_dir){
        graph[d][s].first = bi_dir;
        graph[d][s].second =  wt;
    }
    cout<<"Add Edge done\n";
}

void display(){
    for(auto it: graph){
        for(auto ele: it){
            cout<<"("<<ele.first<<" , "<<ele.second<<"), ";
        }
        cout<<"\n";
    }
}
// 1 0 4
// 0 3 5
// 0 5 7
// 1 2 9
// 2 3 2
// 5 6 1
// 5 4 0

int main(){
    
    cout<<"Enter vertices: ";
    cin>>v;
    graph.resize(v,vector<pair<bool,int>>(v,{0,-1}));

    int e;
    cout<<"Enter Edges: ";
    cin>>e;

    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s, d, wt);
    }

    display();
    

    return 0;
}