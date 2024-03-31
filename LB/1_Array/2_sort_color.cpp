// https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0, mid=0, j=n-1;
        while(mid<=j){
            if(nums[mid] == 1) mid++;
            else if(nums[mid] == 0){
                swap(nums[i],nums[mid]);
                mid++, i++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[j]);
                j--;
            }
           
        }
    }
};


int main(){
    

    return 0;
}