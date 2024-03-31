#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int,char>>>graph;
int v;

void add_edge(int s, int d, char color){
    graph[s].push_back({d,color});
    graph[d].push_back({s,color});
}

vector<int> f(int s,int d, char color){
    queue<pair<int,int>>q;
    q.push({s,0});
    vector<int> dis(v,-1);
    dis[s] = 0;
    
    while(!q.empty()){
        auto curr = q.front();
        int node = curr.first;
        int step = curr.second;
        q.pop();
        for(auto it: graph[node]){
            if(dis[it.first]!=-1 || it.second==color) continue;
            q.push({it.first,step+1});
            dis[it.first] = step + 1;
        }
    }
    return dis;
}

int minDis(int s,int d){
    vector<int> red = f(s, d, 'b'); 
    vector<int> blue = f(d, s, 'r'); 

    int mini =  1e8;
    
    for(int i=0; i<v; i++){
        if(blue[i]==-1 || red[i]==-1) continue;
        mini = min(blue[i]+red[i] , mini);
    }

    return mini;
}


int main(){
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    cin>>v;
    graph.resize(v, list<pair<int,char>>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        char color;
        cin>>color;
        add_edge(s,d,color);
    }    

    int s,d;
    cin>>s>>d;
    cout<<minDis(s,d);

    return 0;
}
// 8
// 11
// 0 1 r
// 1 3 r
// 0 3 b
// 0 2 r
// 2 4 b
// 3 4 b
// 3 5 r 
// 5 4 r
// 4 7 b
// 5 6 r
// 6 7 b
// 0 7
// 3