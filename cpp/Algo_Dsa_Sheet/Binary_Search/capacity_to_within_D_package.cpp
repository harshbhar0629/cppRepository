#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution
{

    bool isPossible(vector<int> &wt, int mid, int D)
    {
        int cnt = 1;
        int capacity = 0;
        for (int i = 0; i < wt.size(); i++)
        {
            if (capacity + wt[i] <= mid)
            {
                capacity += wt[i];
            }
            else
            {
                capacity = 0;
                capacity += wt[i];
                cnt++;
            }
        }
        if (cnt > D)
        {
            return false;
        }
        return true;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int lo = 0, hi = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            lo = max(lo, weights[i]);
            hi += weights[i];
        }

        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(weights, mid, days))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}