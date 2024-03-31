#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
bool flag = false;
int f(vector<int>& nums, int i, int target){
    
    if(target==0) {
        flag = true;
        return 0;
    }
    if(i==nums.size()) return 0;
    if(dp[i][target]!=-1) return dp[i][target];
    
    int a = f(nums, i+1, target);
    int b = 0;
    if(nums[i]<=target){
        b = 1+f(nums, i+1, target-nums[i]);
    }
    
    return dp[i][target] = max(a,b);       
}

int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    flag = false;
    memset(dp , -1, sizeof dp);
    int ans = f(nums, 0, target);
    if(flag) return ans;
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0; i<n ;i++){
        cin>>v[i];
    }

    int target;
    cin>>target;
    cout<<lengthOfLongestSubsequence(v, target);

    return 0;
}