#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

class Solution
{
    typedef long long int ll;

public:
    long long largestPerimeter(vector<int> &nums)
    {
        if (nums.size() < 3)
            return -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll cnt = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= 2 and sum > nums[i])
            {
                cnt = sum + nums[i];
            }
            sum += nums[i];
        }
        return cnt == 0 ? -1 : cnt;
    }

    long long largestPerimeter(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (nums.size() < 3)
            return -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] > nums[i])
            {
                ans = prefix[i + 1];
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

int main(){
    

    return 0;
}