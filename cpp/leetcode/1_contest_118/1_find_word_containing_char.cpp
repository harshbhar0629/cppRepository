// https://leetcode.com/contest/biweekly-contest-118/problems/find-words-containing-character/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        int n = words.size();
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}