#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum-ii/

class Solution {

    vector<vector<int>>ans;
    void f(int i, int target, vector<int>& v, vector<int>& cand){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==cand.size()){
            return;
        }
        for(int j=i; j<cand.size(); j++){
            if(j!=i and cand[j] == cand[j-1]){
                continue;
            }
            if(cand[j] <= target){
                v.push_back(cand[j]);
                f(j+1, target-cand[j], v, cand);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(), candidates.end());
        f(0, target, v, candidates);   
        return ans;
    }
};

int main(){
    

    return 0;
}