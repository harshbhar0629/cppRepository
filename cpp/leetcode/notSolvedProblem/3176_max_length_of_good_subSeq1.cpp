#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/

class Solution {
    // int dp[505][30][505];
    int dp[505][30];
    vector<int>nums;
    
    // int f(int i, int k, int last){
    //     if(i == nums.size()){
    //         return 0;
    //     }
    //     if(dp[i][k][last] != -1){
    //         return dp[i][k][last];
    //     }
        
    //     int ans = f(i+1, k, last);
        
    //     if(nums[i] != nums[last] and k>0){
    //         ans = max(ans, 1+ f(i+1, k-1, i));
    //     }
    //     if(nums[i] == nums[last]){
    //         ans = max(ans, 1+ f(i+1, k, i));
    //     }
    //     // cout<<i<<" "<<last<<"\n";
    //     return dp[i][k][last] = ans;
    // }

    int f(int i, int k){
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        int ans = 1;
        for(int j=0; j<i; j++){
            if(nums[i] == nums[j]){
                ans = max(ans, 1+ f(j, k));
            }
            else{
                if(k) ans = max(ans, 1+ f(j, k-1));
            }
        }

        return dp[i][k] = ans;
    }
    
public:
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        this->nums = nums;
        
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, f(i, k));
        }
        
        return maxi;
    }
};


int main(){
    

    return 0;
}