#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int maxi = nums[0],step=nums[0], jump=1;
        
        if(n==1) return 0;
        
        for(int i=1; i<n; i++){
            if(i==n-1) return jump;
            step--;
            maxi = max(maxi, i+nums[i]);
            if(step==0){
                jump++;
                step = maxi - i;
            }
        }
        return jump;
    }
};


// https://leetcode.com/problems/jump-game-i/
class Solutions {
public:
    bool canJump(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int maxi = nums[0],step=nums[0];
        
        if(n==1) return true;
        if(nums[0]==0) return false;
        
        for(int i=1; i<n; i++){
            if(i==n-1) return true;
            step--;
            maxi = max(maxi, i+nums[i]);
            if(step==0){
                if(i>=maxi) return false;
                step = maxi - i;
            }
        }
        return false;
    }
};

int main(){
    

    return 0;
}