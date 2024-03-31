#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v;
    

void add_edge(int s, int d, int wt, bool bi_dir = true){
    graph[s].push_back({d,wt});
    if(bi_dir){
        graph[d].push_back({s,wt});
    }
    cout<<"Add Edge done\n";
}


void display(){
    int k=0;
    for(auto it: graph){
        cout<<k++<<" -> ";
        for(auto ele: it){
            cout<<" ("<<ele.first<<" , "<<ele.second<<"), ";
        }cout<<"\n";
    }
}


int main(){
    cout<<"Enter vertices: ";
    cin>>v;
    graph.resize(v, list<pair<int,int>>());
    cout<<"Enter edge: ";
    int e; //edge or input
    cin>>e;

    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s, d, wt);
    }

    display();


    return 0;
}