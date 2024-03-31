#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pq;
        for (int i = 1; i < n; i++)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0)
            {
                continue;
            }
            else if (diff <= bricks)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0)
            {
                if (!pq.empty() and pq.top() >= diff)
                {
                    bricks += pq.top() - diff;
                    pq.pop();
                    pq.push(diff);
                }
                ladders--;
            }
            else
            {
                return i - 1;
            }
        }
        return n - 1;
    }
};

int main(){
    

    return 0;
}