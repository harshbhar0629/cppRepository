#include <bits/stdc++.h>
using namespace std;


vector<list<int>>graph;
int v;

void add_edge(int s, int d, bool bi_dir = true){

    graph[s].push_back(d);

    if(bi_dir){
        graph[d].push_back(s);
    }
    // cout<<"Edge done\n";
}


bool topoBFS(){
    // kahn's algorithm--->>applicable for DAG not for cyclic

    vector<int>indegree(v,0);
    unordered_set<int>vis;
    queue<int>q;

    for(int i=0; i<v; i++){
        for(auto it: graph[i]){
            indegree[it]++;
        }
    }

    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            vis.insert(i);
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it: graph[node]){
            if(not vis.count(it)){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    vis.insert(it);
                }
            }
        }
    }
    cout<<endl;
    return vis.size()==v;
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

    cout<<topoBFS();

    return 0;
}