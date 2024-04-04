#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] == nums[lo] and nums[mid] == nums[hi])
            {
                lo++, hi--;
            }
            else if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target and target <= nums[mid])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target and target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(){
    

    return 0;
}