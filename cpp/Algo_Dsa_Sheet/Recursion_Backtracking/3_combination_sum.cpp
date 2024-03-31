#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum/

class Solution {
    vector<vector<int>>ans;
    void f(int i, int target, vector<int>& v, vector<int>& cand){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(i==cand.size()){
            return;
        }

        f(i+1, target, v, cand);
        if(cand[i] <= target){
            v.push_back(cand[i]);
            f(i, target-cand[i], v, cand);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        f(0, target, v, candidates);

        return ans;
    }
};

int main(){
    

    return 0;
}