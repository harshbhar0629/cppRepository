#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-characters-by-frequency/

#define pi pair<int, char>
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }

        priority_queue<pi> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int cnt = it.first;
            char ch = it.second;
            while (cnt--)
            {
                ans += ch;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}