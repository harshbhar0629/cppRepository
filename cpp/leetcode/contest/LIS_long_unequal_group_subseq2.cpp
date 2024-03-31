// https://leetcode.com/contest/biweekly-contest-115/problems/longest-unequal-adjacent-groups-subsequence-ii//
#include <bits/stdc++.h>
using namespace std;

// calculate hamming distance
int hammingDistance(string s, string t){
    int dis=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=t[i]) dis++;
    }
    return dis;
}


vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>&groups){
    // points:
    // hamming distance between two words is 1
    //word length should be equal
    //adjacent group should not be equal
    
    int n = words.size(), maxi=0, idx = 0;
    vector<int>dp(n,1), hash(n);
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int j=0; j<i; j++){
            if(groups[i]!=groups[j] and words[i].size()==words[j].size() and hammingDistance(words[i],words[j]) == 1){
                //means all condition will satisfy
                if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j; //like backtrack
                }
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            idx = i;
        }
    }

    vector<string>ans;
    ans.push_back(words[idx]);
    while(hash[idx]!=idx){
        idx = hash[idx];
        ans.push_back(words[idx]);
    }

    reverse(ans.begin(),ans.end());
    return ans;

}


int main(){
    

    return 0;
}