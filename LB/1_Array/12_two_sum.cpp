// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
   vector<int> twoSum(vector<int>&nums ,int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if( mp.find(target - nums[i]) != mp.end() ){
                int a = mp[target- nums[i]];
                return {i,a};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};

        // for(int i=0;i<nums.size();i++){
        //     int t= target - nums[i];
        //     int idx = mp[t];
        //     if(idx!=0 and idx!=i) return{i,idx};
        // }
        // return{ };
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        // vector<pair<int,int>>v;
        // for(int i=0;i<nums.size();i++){
        //     v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // int i=0,j=nums.size()-1;
        // while(i<j){
        //     int sum = v[i].first + v[j].first;
        //     if(sum==target) return {v[i].second , v[j].second};
        //     else if(sum>target) j--;
        //     else i++;
        // }

        // return { };
    }
};

int main(){
    

    return 0;
}