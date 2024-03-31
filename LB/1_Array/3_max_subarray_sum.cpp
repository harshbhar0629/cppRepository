// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;


class solution{
public:
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e6 , temp = -1e6;
        for(int i=0; i<n; i++){
            temp = max(temp + nums[i], nums[i]);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};



int main(){
    

    return 0;
}