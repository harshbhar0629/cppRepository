#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0);
        for(auto& x: trust){
            in[x[0]]--;
            in[x[1]]++;
        }
        for(int i=1; i<n+1; i++){
            if(in[i]==n-1) return i;
        }
        return -1;
    }
};

int main(){
    

    return 0;
}