#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v;

void add_edge(int s, int d, bool bi_dir=true){
    graph[s][d]++;
    if(bi_dir){
        graph[d][s]++;
    }
    cout<<"Add Edge done\n";
}

void display(){
    for(auto it: graph){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
// 1 0
// 0 3
// 0 5
// 1 2
// 2 3
// 5 6
// 5 4

int main(){
    
    cout<<"Enter vertices: ";
    cin>>v;
    graph.resize(v,vector<int>(v,0));

    int e;
    cout<<"Enter Edges: ";
    cin>>e;

    while(e--){
        int s,  d;
        cin>>s>>d;
        add_edge(s, d);
    }

    display();
    

    return 0;
}