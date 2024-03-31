#include <bits/stdc++.h>
using namespace std;


#define ll long long int
class Solution {
    // ll dp[100005][2];
    // ll f(vector<int>&nums, int i, bool flag){
    //     if(i>=nums.size()) return 0;
    //     if(dp[i][flag]!=-1) return dp[i][flag];

    //     ll skip = f(nums, i+1, flag);
    //     // take
    //     int val = nums[i];
    //     if(!flag){
    //         val = -val;
    //     }

    //     ll take = f(nums, i+1, !flag) + val;
    //     return dp[i][flag] = max(take, skip);
    // }

public:
    ll maxAlternatingSum(vector<int>& nums) {
        // memset(dp, -1, sizeof dp);
        ll maxi =0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            maxi += max(0, (nums[i-1]-nums[i]));
        }
        return maxi+nums.back();
        // return f(nums, 0, true);
    }
};


int main(){
    

    return 0;
}