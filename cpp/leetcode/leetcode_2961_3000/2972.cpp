#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/

#define ll long long int

class Solution{
public:
    // SC:O(n) and TC: (NlogN)
    ll incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right;

        int i = 0;
        //left-part
        while(i<n-1 and nums[i] < nums[i+1]){
            left.push_back(nums[i]);
            i++;
        }
        left.push_back(nums[i]);

        //right-part
        int j = n - 2;
        while(j>=0 and nums[j] < nums[j+1]){
            right.push_back(nums[j+1]);
        }
        right.push_back(nums[j + 1]);

        reverse(right.begin(), right.end());

        if(j<i){
            ll cnt = n;
            return cnt * (cnt + 1) / 2;
        }
        int i = 0, left_size = left.size() , right_size = right.size();
        // left consider na karen to right.size() wale array k each element have one choice to be consider so we will add one for each element
        ll cnt = right_size + 1;

        while (i < left_size){
            int l = left[i];
            int start_idx = upper_bound(right.begin(), right.end(), l) - right.begin();

            cnt += (right_size - start_idx + 1);
            i++;
        }

        return cnt;
    }
};

#define ll long long int
class Solution{
public:
    //SC: O(1) and TC:O(NlogN)
    ll incremovableSubarrayCount(vector<int> &nums){

        int n = nums.size();
        int left = 0;
        // left-part
        while (left < n - 1 and nums[left] < nums[left + 1])
        {
            left++;
        }

        // right-part
        int right = n - 1;
        while (right > 0 and nums[right - 1] < nums[right])
        {
            right--;
        }

        ll cnt = (left == n - 1) ? 0 : (n - right) + 1;
        int i = 0;
        while (i <= left)
        {
            int l = nums[i];
            int start_idx = upper_bound(nums.begin() + right, nums.end(), l) - nums.begin();
            cnt += (n - start_idx) + 1;
            i++;
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}