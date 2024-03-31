#include<bits/stdc++.h>
using namespace std;
// leetcode 781
// https://leetcode.com/problems/rabbits-in-forest/submissions/1170685449/

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {

        int ans = 0;
        unordered_map<int, int> mp;
        for (auto ele : answers)
        {
            if (mp.find(ele) == mp.end())
            {
                ans += (ele + 1);
            }
            mp[ele]++;
            if (mp[ele] > ele)
            {
                mp.erase(ele);
            }
        }
        return ans;
    }
};

int main(){

    vector<int> v={1,2,3,1,2,3,1};
    Solution s;
    int ans = s.numRabbits(v);
    cout<<ans;
}