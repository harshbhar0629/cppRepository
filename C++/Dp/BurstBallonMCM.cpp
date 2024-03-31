// https://leetcode.com/problems/burst-balloons/
#define ll long long int
class Solution {
        
    int dp[305][305];
    int ftd(vector<int>&v,int i ,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = -1e8;
        for(int k=i; k<j; k++){
            ans = max(ans,ftd(v,i,k) + ftd(v,k+1,j) + v[i-1]*v[k]*v[j]);
        }

        return dp[i][j] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof dp);
        return ftd(nums,1,nums.size()-1);
    }
};