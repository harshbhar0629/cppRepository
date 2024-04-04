#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int max_reach = startFuel;
        int n = stations.size();
        priority_queue<int> pq;
        int cnt = 0;
        int i = 0;

        while (max_reach < target)
        {
            while (i < n and stations[i][0] <= max_reach)
            {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty())
            {
                return -1;
            }
            cnt++;
            max_reach += pq.top();
            pq.pop();
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}