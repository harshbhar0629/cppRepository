#include <bits/stdc++.h>
using namespace std;


vector<list<int>>graph;
stack<int>st;
int v;

void add_edge(int s, int d, bool bi_dir = true){

    graph[s].push_back(d);

    if(bi_dir){
        graph[d].push_back(s);
    }
    // cout<<"Edge done\n";
}


void dfs(int node, vector<bool>& vis){
    vis[node]=1;
    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it, vis);
        }
    }
    st.push(node);
}



void topo_DFS(){

    vector<bool>vis(v,0);

    for(int i=0; i<v; i++){
        if(vis[i]==0){
            dfs(i, vis);
        }
    }

    vector<int>ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

}


int main(){
    cin>>v;
    graph.resize(v,list<int>());

    int e;
    cin>>e;

    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s, d, false);
    }

    return 0;
}