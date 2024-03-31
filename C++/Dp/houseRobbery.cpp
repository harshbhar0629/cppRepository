// https://leetcode.com/problems/house-robber/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  
    int robbery(vector<int>&v,int i){
        if(i>=v.size()) return 0;
        return max(v[i]+robbery(v,i+2) , robbery(v,i+1));
    }
  
    vector<int>dp;
    int robberyOpt(vector<int>&v,int i){
        if(i>=v.size() ){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        dp[i] = max(v[i] + robberyOpt(v,i+2), robberyOpt(v,i+1));
        return dp[i];
    }

    int bottomUp(vector<int>&v){
        int n = v.size();
        dp.resize(n+1,0);
        dp[n-1] = v[n-1];
        for(int i=n-2; i>=0; i--){
            dp[i] = max(v[i]+dp[i+2] , dp[i+1]);
        }
        return dp[0];
    }

    int bottomUp2(vector<int>&v){
        if(v.size()==1) return v[0];
        int n = v.size();
        int p2= v[n-1];
        int p1 = v[n-2];
        for(int i=n-3; i>=0; i--){
            int curr = max(v[i]+p2,p1);
            p2 = max(p1,p2);
            p1 = max(curr,p1);
        }
        return max(p2, p1);
    }

public:
    int rob(vector<int>& nums) {

        // int ans = robbery(nums,0);
        // return ans;

        // dp.resize(nums.size()+1,-1);
        // int ans = robberyOpt(nums,0);
        // return ans;

        // int ans = bottomUp(nums);
        // return ans;

        // return bottomUp2(nums);
    }
};


int main(){
    

    return 0;
}