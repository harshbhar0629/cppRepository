#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

class Solution{
    // TC: O(NlogN) SC: O(1)
    int approach1(vector<int>& nums){
        int n = nums.size();
        if (n <= 4){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++){
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }

        return ans;
    }

    //  TC: O(N) SC: O(1)
    int approach2(vector<int>& nums){
        int n = nums.size();
        if (n <= 4){
            return 0;
        }

        nth_element(nums.begin(), nums.begin() + 4, nums.end());   // its set 4 smallest element in the front of array and 4th element will be in correct position
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end()); // its set 4 largest element in the end of array and 4th element will be in correct position
        
        sort(nums.begin(), nums.begin() + 4); // sort only first 3 element
        sort(nums.end() - 4, nums.end()); // sort only last 3 element
        // for(int i=0; i<n; i++) cout<<nums[i]<<" ";

        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++){
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }

        return ans;
    }

public:
    int minDifference(vector<int> &nums){
        // return approach1(nums);
        return approach2(nums);
    }
};


int main(){
    

    return 0;
}