#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-ii/

class Solution {
    int dp[5005][55];
    // inside inner loop we r computing the max of same value o/w find max of prev value those who are not equal
    // for(int j=0; j<i; j++){
    //     if(nums[i] == nums[j]){
    //         ans = max(ans, 1+ dp[j][x]);
    //     }
    //     if(x) ans = max(ans, 1+ dp[j][x-1]);
    // }
public:
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, 0, sizeof dp);
        // this->nums = nums;
        for(int x=0; x<=k; x++){
            int curr_j_1_maxi=0;
            unordered_map<int,int>same_val_max;

            for(int i=0; i<nums.size(); i++){
                int ans = 1;
               
                ans = max(ans, 1+ same_val_max[nums[i]]);
                if(x) ans = max(ans, 1+ curr_j_1_maxi);
                dp[i][x] = ans;

                same_val_max[nums[i]] = max(same_val_max[nums[i]], ans);
                if(x) curr_j_1_maxi = max(dp[i][x-1], curr_j_1_maxi);
            }
        }        
                

        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, dp[i][k]);
        }
        
        return maxi;
    }
};

int main(){
    

    return 0;
}