#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

class Solution
{
    const int mod = 1e5;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
        {
            return 0;
        }
        queue<pair<int, int>> qu;
        qu.push({start, 0});
        vector<int> dis(100005, 1e8);
        dis[start] = 0;

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            int num = curr.first;
            int steps = curr.second;

            for (int it : arr)
            {
                int val = (it * num) % mod;
                if (dis[val] > steps + 1)
                {
                    dis[val] = steps + 1;
                    qu.push({val, steps + 1});
                    if (val == end)
                    {
                        return steps + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    

    return 0;
}