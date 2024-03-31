// https://leetcode.com/contest/biweekly-contest-115/problems/longest-unequal-adjacent-groups-subsequence-i/
#include <bits/stdc++.h>
using namespace std;


vector<string> getWordsInLongestSubsequence(int n, vector<int>&groups, vector<string>&word){
    vector<string>ans;
    for(int i=0; i<n; i++){
        if(i==0 || groups[i]!=groups[i-1]){
            ans.push_back(word[i]);
        }
    }
    return ans;
}


int main(){
    

    return 0;
}