#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-all-people-with-secret/description/

class Solution {
    // vector<int> solve(int n, vector<vector<int>>& meetings, int firstPerson){
        // O(M(M+N))
        // unordered_map<int,vector<pair<int,int>>>graph;
        // for(auto& meet: meetings){
        //     int xi = meet[0];
        //     int yi = meet[1];
        //     int time = meet[2];
        //     graph[xi].emplace_back(yi, time);
        //     graph[yi].emplace_back(xi, time);
        // }

        // vector<int>people(n,INT_MAX);
        // queue<pair<int,int>>q;

        // q.push({0,0});
        // q.push({firstPerson,0});
        // people[firstPerson] = people[0] = 0;

        // while(!q.empty()){
        //     auto [person, time] = q.front();
        //     q.pop();

        //     for(auto [nextPerson, nextTime]: graph[person]){
        //         if(nextTime >= time and people[nextPerson] > nextTime){
        //             people[nextPerson] = nextTime;
        //             q.push({nextPerson, people[nextPerson]});
        //         }
        //     }
        // }

        // vector<int>ans;
        // for(int i=0; i<n; i++){
        //     if(people[i] != INT_MAX){
        //         ans.push_back(i);
        //     }
        // }

        // return ans;
    // }

    vector<int>par;
    vector<int>rank;

    int find(int x){
        if(par[x] == -1){
            return x;
        }

        return par[x] = find(par[x]);
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    void reset(int x){
        par[x] = -1;
        rank[x] = 0;
    }

    void Union(int x, int y){
        int parX = find(x);
        int parY = find(y);

        if(parX == parY){
            return;
        }

        if(rank[parX] >= rank[parY]){
            rank[parX]++;
            par[parY] = parX;
        }
        else{
            rank[parY]++;
            par[parX] = parY;    
        }
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        map<int,vector<pair<int,int>>>graph;
        rank.resize(n, 0);
        par.resize(n, -1);

        // O(MlogM)
        for(auto meet: meetings){
            int xi = meet[0];
            int yi = meet[1];
            int time = meet[2];
            graph[time].emplace_back(xi,yi);
        }

        Union(firstPerson, 0);
        for(auto it: graph){
            // O(M)
            // we will make a dotted connection 
            for(auto meet: it.second){
                int x = meet.first;
                int y = meet.second;
                Union(x, y);
            }
            // O(M)
            // disconnect the dotted connection if it is not know the secret
            for(auto meet: it.second){
                int x = meet.first;
                int y = meet.second;
                if(!isConnected(x,0)){
                    reset(x);
                    reset(y);
                }
            }
        }

        // O(N)
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(isConnected(i,0)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};


int main(){
    

    return 0;
}