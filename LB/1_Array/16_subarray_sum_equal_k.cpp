// https://leetcode.com/problems/subarray-sum-equals-k/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        unordered_map<int,int>mp;
        int n = nums.size(), count = 0;
        
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }

        for(int i=0; i<n; i++){
            if(nums[i]==k) count++;
            int rem = nums[i] - k;
            if(mp[rem]>0) count+=mp[rem];
            mp[nums[i]]++;
        }
        return count;
    }
};

int main(){
    

    return 0;
}