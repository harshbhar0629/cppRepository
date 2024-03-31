#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-game/description/

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        vector<int> ans;
        while (!pq.empty())
        {
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};

int main(){


    return 0;
}