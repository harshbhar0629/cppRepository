#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/get-watched-videos-by-your-friends/

class Solution {
    using pis = pair<int,string>;

    static bool cmp(const auto& x, const auto& y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        return x.first > y.first;
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n = friends.size();
        queue<int>qu;
        qu.push(id);
        vector<bool>vis(n,0);

        while(!qu.empty() and level--){
            int s = qu.size();

            for(int i=0; i<s; i++){
                int curr = qu.front();
                qu.pop();
                vis[curr] = true;

                for(auto it: friends[curr]){
                    if(!vis[it]){
                        qu.push(it);
                    }
                }
            }
        }
    
        vector<string>res;
        unordered_map<string,int>mp;
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto s: watchedVideos[curr]){
                mp[s]++;
            }
        }

        vector<pis>v;
        for(auto it: mp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            res.push_back(v[i].second);
        }

        // priority_queue<pis, vector<pis>, greater<pis>>pq;
        // for(auto it: mp){
        //     pq.push({it.second, it.first});
        // }
        
        // while(!pq.empty()){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        return res;
    }
};


int main(){
    

    return 0;
}