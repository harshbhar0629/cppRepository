#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-closest-points-to-origin/

#define pp pair<double, pair<int, int>>
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        if (k == points.size())
        {
            return points;
        }

        priority_queue<pp> pq;
        for (auto point : points)
        {
            double dis = sqrt((point[0] - 0) * (point[0] - 0) + (point[1] - 0) * (point[1] - 0));
            if (pq.size() < k)
            {
                pq.push({dis, {point[0], point[1]}});
            }
            else if (pq.top().first > dis)
            {
                pq.pop();
                pq.push({dis, {point[0], point[1]}});
            }
        }

        vector<vector<int>> res;
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            res.push_back({curr.second.first, curr.second.second});
        }

        return res;
    }
};

int main(){
    

    return 0;
}