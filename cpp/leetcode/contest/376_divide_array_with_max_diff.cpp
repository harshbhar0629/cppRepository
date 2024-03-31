// https://leetcode.com/contest/weekly-contest-376/problems/divide-array-into-arrays-with-max-difference/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0;
        // bool flag = true;
        vector<vector<int>>res;
        
        while(i<n){
            vector<int>v;
            int size = 3;
            bool flag = true;
            
                for(; i<n and size--; i++){
                    if(v.size()==0){
                        v.push_back(nums[i]);
                    }
                    else if(v.size()==1){
                        if(abs(v.back() - nums[i]) <= k)
                            v.push_back(nums[i]);
                        else {
                            flag = false;
                            break;
                        }
                    }
                    else if(v.size()==2){
                        if(abs(v[0] - nums[i]) <= k and abs(v[1] - nums[i]) <= k){
                            v.push_back(nums[i]);
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }

                }
            if(flag and v.size()==3) res.push_back(v);
            
        }
        if(n != 3*res.size()) return {};
        return res;
        
    }
};

int main(){
    

    return 0;
}