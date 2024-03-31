#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subsets-ii/submissions/1131124206/

class Solution {

    void f(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        res.push_back(temp);

        for(int idx = i; idx<nums.size(); idx++){
            if(i!=idx and nums[idx] == nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            f(idx+1, nums, temp, res);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }

        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());

        f(0, nums, temp, res);

        return res;
    }
};


int main(){
    

    return 0;
}