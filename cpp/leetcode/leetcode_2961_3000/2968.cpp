#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/

#define ll long long int
class Solution
{
    bool f(vector<int> &nums, vector<ll> &pre, ll k, int mid)
    {
        int i = 0, j = mid - 1; // j-i == len

        int n = nums.size();
        while (j < n)
        {
            int mid_idx = (i + j) / 2;
            ll target = nums[mid_idx];

            ll oprn_left = 0;
            ll oprn_right = 0;

            oprn_left = abs((mid_idx - i) * target - (pre[mid_idx] - pre[i]));
            oprn_right = abs((j - mid_idx) * target - (pre[j + 1] - pre[mid_idx + 1]));

            if (oprn_left + oprn_right <= k)
                return true;
            i++, j++;
        }
        return false;
    }

public:
    int maxFrequencyScore(vector<int> &nums, long long k)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }

        int ans = 1, lo = 1, hi = n;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (f(nums, pre, k, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
        
    }

    int f(vector<int>& nums, ll k, ll ele){
        int n = nums.size();
        ll sum =0 ;
        int len =0, i=0, j=0;

        while(i<n){
            sum += abs(ele-nums[i]);
            while(j<n and sum>k){
                sum -= abs(ele - nums[j]);
                j++;
            }
            i++;
            len = max(len, i-j);
        }
        return len;
    }

    int maxFrequencyScore(vector<int> &nums, long long k)
    {
        int maxi = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            maxi = max(maxi, f(nums, k, nums[i]));
        }
        return maxi;
    }
};

int main(){
    

    return 0;
}