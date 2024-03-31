#include <bits/stdc++.h>
using namespace std;

int dp[10005];
bool f(vector<int>& nums, int i=0){
    if(i >= nums.size()-1){
        return true;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    if(nums[i] > nums.size() -1 -i)return dp[i] = true;

    bool ans = false;
    for(int j=1; j<=nums[i]; j++){
        if(i+j == nums.size() -1) return dp[i] = true;
        if(i+j > nums.size()) continue;
        ans = ans || f(nums, i+ j);
        if(ans) return dp[i] = true;
    }

    return dp[i] = ans;
}

bool canJump(vector<int>& nums){
    memset(dp, -1, sizeof dp);
    return f(nums);
}

bool canJumpOpt(vector<int>& nums){

    int n = nums.size();
    if (n == 1)
    {
        return true;
    }
    if (nums[0] == 0)
    {
        return false;
    }

    int steps = nums[0];
    int maxi = 0;
    for (int i = 1; i < n; i++)
    {
        steps--;
        maxi = max(maxi, i + nums[i]);

        if (steps == 0)
        {
            if (maxi <= i and (i + 1 != n))
            {
                return false;
            }
            steps = maxi - i;
            maxi = i;
        }

        if (n == i + 1)
        {
            return true;
        }
    }

    return false;
}

int main(){
    

    return 0;
}