#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-break-ii/


class Solution {

    vector<string>res;
    unordered_map<string,int>mp;
    void f(string& s, int i, string t){
        int n = s.size();
        if(i>=n){
            t.pop_back();
            res.push_back(t);
            return ;
        }
        string temp = "";
        for(int j=i; j<n; j++){
            temp+=s[j];
            if(mp.count(temp) > 0){
                f(s, j+1, t+ temp + ' ');
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        res.clear();
        mp.clear();
        for(auto it: wordDict){
            mp[it]++;
        }
        f(s, 0, "");
        return res;
    }
};


int main(){
    

    return 0;
}