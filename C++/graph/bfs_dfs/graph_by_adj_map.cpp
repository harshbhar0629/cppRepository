#include <bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;
    

void add_edge(int s, int d, int wt, bool bi_dir = true){
    graph[s][d] = wt;
    if(bi_dir){
        graph[d][s] = wt;
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
    graph.resize(v, unordered_map<int,int>());
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