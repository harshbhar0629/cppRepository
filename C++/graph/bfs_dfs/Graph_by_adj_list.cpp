#include <bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
int v;

/// @brief 
/// @param s source
/// @param d destination
/// @param flag if true then bidirectional otherwise directional  
/// @returns

void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Add Edge done\n";
}


void display(){
    int k=0;
    for(auto it: graph){
        cout<<k++<<" -> ";
        for(auto ele: it){
            cout<<ele<<" , ";
        }cout<<"\n";
    }
}


int main(){
    cout<<"Enter vertices: ";
    cin>>v;
    graph.resize(v, list<int>());
    cout<<"Enter edge: ";
    int e; //edge or input
    cin>>e;

    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }

    display();


    return 0;
}