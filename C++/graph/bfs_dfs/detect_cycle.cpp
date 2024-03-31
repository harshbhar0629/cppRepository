#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir){
        graph[d].push_back(s);
    }
    cout<<"Add Edge done\n";
}


void display(){
    for(auto it: graph){
        for(auto ele: it){
            cout<<ele<<" ";
        }cout<<"\n";
    }
}


bool detectCycleUsingBfs(int s,vector<bool>& visited){

    queue<pair<int,int>>q;
    q.push({s,-1});
    visited[s]=1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbour: graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                q.push({neighbour,node});
            }
            else if(parent != neighbour){
                return true;
            }
        }
    }

    return  false;

}

bool detectCycleUsingDfs(int src, int parent, vector<bool>& vis){
        vis[src] = 1;
        for(auto neighbour: graph[src]){
            if(!vis[neighbour]){
                if(detectCycleUsingDfs(neighbour, src, vis)) return true;
            }
            else if(parent != neighbour) return true;
        }
        return false;
    }
// 6
// 6
// 0 1
// 0 2
// 2 3
// 1 4
// 3 5
// 4 5


int main(){

    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());

    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d);
    }

    display();
    vector<bool> visited(v,0);
    bool flag = true;

    // it also include connected component:
    for(int i=0; i<v; i++){
            if(!visited[i]){
                if(detectCycleUsingBfs(i, visited)){
                    cout<<"true\n";
                    flag = false;
                    break;
                }
            }
    }

    if(flag) cout<<"False\n";
    flag = true;
    vector<bool>vis(v,0);

    // for(int i=0;i<v; i++){
    //     cout<<visited[i]<<" ";
    // }cout<<endl;


    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(detectCycleUsingDfs(i,-1, vis)){    
                flag = false;
                cout<<"Dfs-> true\n";
                break;
            }
        }
    }

    if(flag) cout<<"False";

    return 0;
}