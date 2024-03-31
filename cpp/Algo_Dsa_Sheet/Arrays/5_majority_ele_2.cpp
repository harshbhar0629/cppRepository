#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/majority-element-ii/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto it : mp)
        {
            if (it.second > n / 3)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n;)
        {
            int cnt = 0;
            int num = nums[i];

            while (i < n and num == nums[i])
            {
                i++, cnt++;
            }
            if (cnt > n / 3)
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int num1 = 0, num2 = 1;

        for (auto &num : nums)
        {
            if (num == num1)
            {
                cnt1++;
            }
            else if (num == num2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                num1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                cnt2 = 1;
                num2 = num;
            }
            else
            {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto &num : nums)
        {
            cnt1 += (num == num1);
            cnt2 += (num == num2);
        }

        vector<int> ans;
        if (cnt1 > nums.size() / 3)
        {
            ans.push_back(num1);
        }
        if (cnt2 > nums.size() / 3)
        {
            ans.push_back(num2);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}