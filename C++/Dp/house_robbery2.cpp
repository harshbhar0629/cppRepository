// https://leetcode.com/problems/house-robber-ii/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
    int dp[105];
    int f(vector<int>& nums, int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = max(f(nums,i+1,n), nums[i] + f(nums,i+2,n));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        memset(dp,-1,sizeof dp);
        int a = f(nums, 0, n-1); 
        memset(dp,-1,sizeof dp);
        int b = f(nums,1,n);

        return max(a,b);
    }
};


int main(){
    

    return 0;
}