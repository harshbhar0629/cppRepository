#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

// #define f first
// #define s second
#define pp pair<int, pair<int, int>>
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;
        while (k-- and !pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int first_ele = it.second.first;
            int second_ele = it.second.second;
            ans.push_back({nums1[first_ele], nums2[second_ele]});

            if (second_ele + 1 < m)
            {
                pq.push({nums1[first_ele] + nums2[second_ele + 1], {first_ele, second_ele + 1}});
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}