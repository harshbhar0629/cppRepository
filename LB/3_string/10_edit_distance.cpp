// https://leetcode.com/problems/edit-distance/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int dp[505][505];

    int f(int i, int j, string &s, string &t){
        if(i==s.size() and j==t.size()) return 0;
        if(j==t.size()) return s.size()-i;
        if(i==s.size()) return t.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
    
        if(s[i]==t[j]){
            return dp[i][j] = f(i+1, j+1, s,t);
        }
        return dp[i][j] = min({1+f(i, j+1, s, t) , 1+f(i+1, j, s, t) , 1+f(i+1, j+1, s, t)});
    }

public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return f(0,0,word1, word2);
    }
};


int main(){
    

    return 0;
}