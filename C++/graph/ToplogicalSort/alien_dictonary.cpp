#include <bits/stdc++.h>
using namespace std;


string alienOrder(vector<string>& words){
    unordered_map<char,vector<char>>graph;
    unordered_map<char,int>indegree;

    for(auto str: words){
        for(auto ch: str){
            indegree[ch] = 0;
            graph[ch] = {};
        }
    }

    for(int i=0; i<words.size()-1; i++){
        string s = words[i];
        string t =  words[i+1];
        for(int j=0; j<min(s.size(),t.size()); j++){
            if(s[j]!=t[j]){
                graph[s[j]].push_back(t[j]);
                indegree[t[j]]++;
                break;
            }
        }
    }

    queue<char>q;

    for(auto it: indegree){
        if(it.second==0){
            q.push(it.first);
        }
    }

    string ans = "";

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        ans+=curr;

        for(auto it: graph[curr]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(ans.size()==indegree.size()) return ans;
    cout<<"false";
    return "";
}

int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<alienOrder(v);

    return 0;
}