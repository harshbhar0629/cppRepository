// Given weights and values of N items, we need to put these items 
// in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

// Example 1:

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 

#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


struct Item{
    int value;
    int weight;
};


class Solution
{
    static bool cmp(pair<double, int> &r1, pair<double, int> &r2)
    {
        return r1.first > r2.first;
    }

public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++)
        {
            double d = 1.0 * arr[i].value / arr[i].weight;
            ratio.push_back({d, i});
        }

        sort(ratio.begin(), ratio.end(), cmp);

        double ans = 0.0;
        for (int i = 0; i < n; i++)
        {
            int idx = ratio[i].second;
            int wt = arr[idx].weight;
            if (wt <= W)
            {
                ans += arr[idx].value;
                W -= wt;
            }
            else
            {
                ans += 1.0 * W * ratio[i].first;
                W = 0;
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}