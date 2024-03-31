/**
 * construct graph
 * DS - priority_queue<> , visited, distance arr
 * intially insert (0,src) in pq
 * one by one pop root ele
 * mark root is visited
 * pop it and check if yet visited then continue
 * o/w update weight arr
 * go to its neighbour and those are not visited store all of them in pq with their wt
 * 
*/
// https://www.hackerrank.com/challenges/primsmstsub/problem#:~:text=prims%20has%20the%20following%20parameter,number%20of%20the%20starting%20node


#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

vector<list<pp> > graph;
int v;

void add_edge(int s, int d, int wt){
    graph[s].push_back({d,wt});
    graph[d].push_back({s,wt});
}

// TC: O(VlogV + ElogV) = O(ElogV)
int prims(int start){
    
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<int>dis(v+1,INT_MAX);
    vector<bool> vis(v+1,0);

    pq.push({0,start});
    int ans =0 , total_edge = 0;

    while(total_edge < v and !pq.empty()){
        auto curr = pq.top();
        pq.pop();
        if(vis[curr.second] == true) { //redundant case means already visited
            continue;
        }
        vis[curr.second] = true;
        total_edge++;
        ans+=curr.first; //store weight of curr node

        for(auto it: graph[curr.second]){
            if(!vis[it.first] and dis[it.first] > it.second){
                pq.push({it.second,it.first});
                dis[it.first] = it.second;
            }
        }
    }

    return ans;
}


int main(){

    cin>>v;    
    graph.resize(v+1, list<pp>());
    int e;
    cin>>e;

    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }

    int start;
    cin>>start;

    cout<<prims(start);

    return 0;
}
// 5 6
// 1 2 3
// 1 3 4
// 4 2 6
// 5 2 2
// 2 3 5
// 3 5 7
// 1
// 15