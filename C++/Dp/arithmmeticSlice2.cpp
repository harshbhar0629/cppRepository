//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/ 
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();        
    vector<unordered_map<ll,ll>> dp(n);
    ll ans =0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            ll diff = nums[i] - nums[j];
            if(dp[j].find(diff) != dp.end()){
                ans += dp[j][diff];
            }
            dp[i][diff] += dp[j][diff] + 1;
        }
    }
    return ans;

}


int main(){
    

    return 0;
}