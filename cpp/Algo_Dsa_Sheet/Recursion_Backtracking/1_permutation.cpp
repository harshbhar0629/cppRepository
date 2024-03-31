#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/permutations/

class Solution
{
    vector<vector<int>> ans;
    void f(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            f(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        f(nums, 0);
        return ans;
    }
};

int main(){
    

    return 0;
}