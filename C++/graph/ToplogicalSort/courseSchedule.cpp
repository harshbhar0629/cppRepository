// https://leetcode.com/problems/course-schedule/
// https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;


bool canFinish(int n, vector<vector<int>>& pre){
    vector<int>indegree(n,0);
    vector<int> graph[n];
    vector<int>ans;
    queue<int>q;

    for(auto it: pre){
        indegree[it[0]]++;
        graph[it[1]].push_back(it[0]);
    }

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return ans.size()==n;
} 

vector<int> findOrder(int n, vector<vector<int>>& pre){
    vector<int>indegree(n,0);
    vector<int> graph[n];
    vector<int>ans;
    queue<int>q;

    for(auto it: pre){
        indegree[it[0]]++;
        graph[it[1]].push_back(it[0]);
    }

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    if(ans.size()==n) return ans;
    rteurn {};
}


int main(){
    

    return 0;
}