#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-break/

class Solution {
    int dp[305];
    bool f(int i, string& s, unordered_map<string,int>& mp){
        if(i==s.size()) return dp[i] = true;
        if(dp[i]!=-1) return dp[i];
        string t = "";
        for(int j=i; j<s.size(); j++){
            t+=s[j];
            if(mp.count(t) > 0){
                bool b = f(j+1, s, mp);
                if(b) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it: wordDict){
            mp[it]++;
        }
        memset(dp, -1, sizeof dp);
        return f(0, s, mp);
    }
};

int main(){
    

    return 0;
}