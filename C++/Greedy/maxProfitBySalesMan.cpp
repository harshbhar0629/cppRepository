#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it: offers){
            mp[it[0]].push_back( {it[1],it[2]} );
        }

        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            vector<pair<int,int>> v= mp[i];

            if(i){
                // store max of prev coming profit / current house gold profit
                dp[i] = max(dp[i-1],dp[i]);
            }

            for(auto x: v){
                if(i){
                    // store in ending index of house max of curr buy house profit / sum of prev maxProfit and now current buy house gold
                    dp[x.first]= max(dp[x.first],dp[i-1]+x.second);
                }
                else{
                    dp[x.first] = max(dp[x.first],x.second);
                }
            }
        }
        return dp[n-1];
    }
};