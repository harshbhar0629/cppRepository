// https://leetcode.com/problems/next-permutation/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1, mIdx=n;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i; 
                break;
            }
        }
        // cout<<idx;
        if(idx==-1) return reverse(begin(nums), end(nums));
        // for(int i=idx+1, j=n-1; i<j; i++,j--){
        //     swap(nums[i], nums[j]);
        // }
        reverse(begin(nums)+idx+1, end(nums));
        for(int i=idx+1; i<n; i++){
            if(nums[idx] < nums[i]){
                mIdx = i;
                break;
            }
        }
        swap(nums[idx], nums[mIdx]);
    }
};


int main(){
    

    return 0;
}